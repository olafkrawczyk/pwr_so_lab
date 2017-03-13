#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2

DIR1=`ls $1`

if [ ! -s $2 ]
then
	echo "File cannot be empty!"
	exit 1
fi

IFS='\n' 
FILE=($(cat $2))

for file in $DIR1
do
	FOUND="false"
	if [ -d $1/$file ]
	then
		FOUND="true"
	fi

	for file2 in $FILE
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


for file in $FILE
do
	FOUND="false"
	for file2 in $DIR1
	do
		if [ -d $file2 -o $file == $file2 ]
		then
			FOUND="true"
			break
		fi
	done

	if [ $FOUND == "false" ]
	then
		echo $file
	fi

echo ------------
echo $FILE
done
