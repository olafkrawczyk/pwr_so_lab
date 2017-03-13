#!/bin/bash

for file in $1/*
do
	if [ -x $file && -f $file ]
	then
		echo Moving $file to $2
		mv $file $2
	fi
done
