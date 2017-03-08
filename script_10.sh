#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2

DIR1=`ls $1`
DIR2=`ls $2`


for file in $DIR1
do
	FOUND="false"
	if [ -d $1/$file ]
	then
		FOUND="true"
	fi

	for file2 in $DIR2
	do
		if [ $file == $file2 ]
		then
			FOUND="true"
			break
		fi
	done

	if [ $FOUND == "false" ]
	then
		echo $file
	fi
done


for file in $DIR2
do
	FOUND="false"
	if [ -d $2/$file ]
	then
		FOUND="true"
	fi

	for file2 in $DIR1
	do
		if [ $file == $file2 ]
		then
			FOUND="true"
			break
		fi
	done

	if [ $FOUND == "false" ]
	then
		echo $file
	fi
done
