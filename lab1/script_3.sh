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

for file in $1/*
do
	if [ -x $file -a -f $file ]
	then
		echo Skipping $file - executable 
	elif [ -f $file ]
	then
		echo Removing $file
		rm $file
	fi
done

