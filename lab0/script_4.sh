#!/bin/bash

NUMBER=$((1))

for	file in `ls -S $1`
do
	echo $1/$file
	if [ -x $1/$file ]
	then
		echo Renaming $file to $file.$NUMBER
		mv $1/$file $1/$file.$NUMBER
		NUMBER=$(($NUMBER + 1))
	fi
done
