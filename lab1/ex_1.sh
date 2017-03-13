#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2

# Skrypt wypisuje wszystkie katalogi z katalogu zadanego jako parametr, w którym znajduje się co najmniej
# jeden plik o takiej samej nazwie jak jakikolwiek plik w katalogu podanym jako parametr.

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

DIR1=`ls -d $1/*/`


for dir_ in $DIR1
do
	FOUND="false"
	for file2 in `ls $dir_`
	do
		for file in `ls $1`
		do
			
			if [ $file == $file2 ] && [ ! -d $file2 ]
			then
				FOUND="true"
				break
			fi
		done
		if [ $FOUND == "true" ]
		then
			break
		fi
	done
	
	if [ $FOUND == "true" ]
	then
		echo $dir_
	fi
done


