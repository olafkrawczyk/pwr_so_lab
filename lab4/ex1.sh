#Olaf Krawczyk 218164 30.03.2017
# W zadanym katalogu znaleźć dowiazania twarde do tych samych plików regularnych i wyświetlić je w postaci inode ścieżka1 ścieżka2
#
#!/bin/bash

if [ "$#" -ne "2" ]
then
	echo Illegal number of parameters
	exit 1
fi
if [ ! -d $1 ]
then
	echo Input should be directory
	exit 2
fi

CNT=0
PREV=" "
dirs=" "
find $1 -printf "%i %p\n" | sort |(  while read inode path
do
	if [ -d $path ]
	then
		continue
	else
		if [ ! $PREV = $inode ]
		then
			if [ "$CNT" -ge "2" ]
			then
				echo $dirs
			fi
			CNT=0
			dirs="$inode $path"
		fi	
		if [ "$PREV" = "$inode" ]
		then
			CNT=`expr $CNT + 1`
			dirs="$dirs $path"
		fi
		PREV=$inode
	fi
done
)
