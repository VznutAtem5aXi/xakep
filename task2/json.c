/*
 * Compile and link with 'gcc json.c -o json -ljson-c -luuid'
 *
 * Packages required: json-c-devel, libuuid-devel
 */
#include <stdio.h>
#include <uuid/uuid.h>
#include <json/json.h>

int countbits(unsigned int v)
{
	int n;
	for (n=0; v; v >>=1)
		if (v & 1)
			++n;
	return n;
}

int main(int ac, char *av[])
{
	int n = (ac == 1) ? 10 : atoi(av[1]);
	int i;

	for (i=1; i <= n; ++i) {
		uuid_t uuid;
		char str[37];

		uuid_generate(uuid);
		uuid_unparse(uuid, str);

		json_object *jobj = json_object_new_object();
		json_object *juuid = json_object_new_string(str);
		json_object *jnumber = json_object_new_int(i);
		json_object *jvalue = json_object_new_int(countbits(i));

		json_object_object_add(jobj, "uuid", juuid);
		json_object_object_add(jobj, "number", jnumber);
		json_object_object_add(jobj, "value", jvalue);

		puts(json_object_to_json_string(jobj));

		json_object_put(jvalue);
		json_object_put(jnumber);
		json_object_put(juuid);
		json_object_put(jobj);
	}
}
