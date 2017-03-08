#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2

touch $2
for file in $1/*
do
	if [ ! -s $file -a -f $file -a $file != $2  ]
	then
		echo $file > $2
		echo Removing file $file
		rm $file
	fi
done

