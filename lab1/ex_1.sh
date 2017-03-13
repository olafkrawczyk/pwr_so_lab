#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2

# Skrypt wypisuje wszystkie katalogi w katalogu zadanym jako parametr, w którym znajduje się
# plik o takiej samej nazwie jak jakikolwiek plik w katalogu podanym jako parametr.

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
	for dir2_ in `ls $dir_`
	do
		for file in `ls $1`
		do
			
			if [ $file == $dir2_ ] && [ ! -d $dir2_ ]
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


