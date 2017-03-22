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
	if [ -d $file -o -L $file ]
	then
		continue
	fi

	for file2 in $1/*
	do
		if [ $file == $file2 -o -d $file2 -o -L $file2 ]
		then
			continue
		fi
		inode1=`stat -c "%i" $file`
		inode2=`stat -c "%i" $file2`
		echo $inode1
		echo $inode2
		if [ $inode1 == $inode2 ]
		then
			rm $file2
			ln -s $file $file2
		fi

	done
done

