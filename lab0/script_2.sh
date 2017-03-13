#!/bin/bash

echo Creating files from $2 in directory $1 ...

for file in `cat $2`
do
	if [ -f "$1"/$file ]
	then
		echo File $file already exists.
	else
		echo Creating file $1/$file ...
		touch $1/$file
	fi
done
