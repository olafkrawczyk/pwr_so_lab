#Olaf Krawczyk 218164 20.04.2017
# W zadanym katalogu znaleźć wszystkie pliki regularne których nazwa znajduje się w jednym z rozszerzeń
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

find $1 -type f -print | egrep '([^/\.])+\..*\1+'
