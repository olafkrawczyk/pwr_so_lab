#!/bin/bash

W_DIR=`dirname $1`
FILES=`cat $1`

cp $1 $1_bak
echo "" > $1

for	file in $FILES 
do
	echo Saving $file...
	echo $file >> $1 
	cat $W_DIR/$file >> $1
done
