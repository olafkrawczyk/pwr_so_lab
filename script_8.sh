#!/bin/bash
# Olaf Krawczyk 218164
# Systemy Operacyjne 2


for item in `ls $1`
do
	if [ -f $1/$item ]
	then
		echo $item
	elif [ -d $1/$item ]
	then
		echo $item

		for	n_item in `ls $1/$item`
		do
			if [ -f $1/$item/$n_item ]
			then
				echo ./$item/$n_item
			elif [ -d $1/$item/$n_item ]
			then
				for file in `ls $1/$item/$n_item `
				do
					echo ./$item/$n_item/$file
				done
			fi
		done
	fi
done
