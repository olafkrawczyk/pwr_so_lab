#Olaf Krawczyk 218164 23.03.2017
#
#W zadanym katalogu znaleźć pliki mające dowaiązania twarde do których właściciel ma prawo odczytu i zapisu, 
#a nie ma prawa wykonaia. Natomiast grupa lub inni mają prawo wykonania
#
#!/bin/bash

if [ "$#" -ne "1" ]
then
	echo Illegal number of parameters
	exit 1
fi
if [ ! -d $1 ]
then
	echo Input should be directory
	exit 2
fi

find $1 -type f -links +1 -perm -u+rw ! -perm -u+x \( -perm -g+x -o -perm -o+x \) -print

