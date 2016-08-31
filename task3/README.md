A self-extracting (SFX) archive is an executable program which contains
a compressed archive with files to be installed and an executable
part ready to be run on target computer which can extract files from 
embedded archive.

This directory contains two examples of such archives.

Design and implement an automatic converter from any kind of SFX archives
to rpm format, as long as SFX can be executed on target computer.
The converted rpm should contain extracted files from the archive,
but not the archive itself.
