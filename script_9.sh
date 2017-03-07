#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2

touch "deleted.txt"
for file in $1/*
do
	if [ ! -s $file -a -f $file -a $file != "deleted.txt" ]
	then
		echo $file > "deleted.txt"
		echo Removing file $file
		rm $file
	fi
done

