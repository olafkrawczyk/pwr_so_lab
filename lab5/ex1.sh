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
if [ ! -d $1 ]
then
	echo Input should be directory
	exit 2
fi


find $1 -type f | awk -F "." '{n=split($0,dir,"/"); f=split(dir[n],filename,"."); if (f >= 3 && filename[f] == filename[2]) print $0;  }'
