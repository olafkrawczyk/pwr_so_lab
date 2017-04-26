#Olaf Krawczyk 218164 06.04.2017
# W zadanym katalogu znaleźć wszystkie pliki regularne z wieloma rozszerzeniami, których pierwsze i
# ostatnie rozszerzenie jest takie samo
#
#!/bin/bash

if [ "$#" -ne "1" ]
then
	echo Illegal number of parameters
	exit 1
fi

find $1 -type f -printf "%i %p\n" | sort | awk 'BEGIN{prev=""; cnt=0; found=0}{if ($1 != prev){prev=$1; cnt=1; found=0}else if(prev == $1 && found == 0){cnt++; files[$1]=$0; found=1;}END{ for (i in files) print files[i]}'  
