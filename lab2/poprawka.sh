#!/bin/bash
#Olaf Krawczyk 218164 30.03.2017
# W zadanym katalogu znaleźć dowiązania symboliczne do plików regularnychw tym katalogu i zamienić je na dowiązania twarde
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

for file in $1/*
do
	if [ -L $file -a -f $file ]
	then
		SYM_POINT=`readlink -f $file`
		if [ `dirname $SYM_POINT` = $1 ]
		then
			echo $file
			echo $SYM_POINT
			rm $file
			ln $SYM_POINT $file
		fi
	fi
done
