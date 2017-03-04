#!/bin/bash

FILENAME=$1/files.txt

if [ -f $FILENAME ]
then
	echo Agregate file already exists..
	echo Removing $FILENAME...
	rm $FILENAME
fi

echo "Creating new files.txt"
touch $FILENAME

for	file in $1/*
do
	if [[ -f $file && $file != $FILENAME ]]
	then
		echo Saving $file
		echo $file >> $FILENAME
		cat $file >> $FILENAME
	fi
done
