#!/bin/bash

for file in $1/*
do
	if [ -x $file ]
	then
		echo Skipping $file - executable 
	elif [ -f $file ]
	then
		echo Removing $file
		rm $file
	fi
done

