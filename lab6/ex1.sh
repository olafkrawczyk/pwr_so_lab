#Olaf Krawczyk 218164 20.04.2017
# W zadanym katalogu znaleźć wszystkie wyrazy, których pierwsze 3 litery są takie same.
#!/bin/bash

if [ "$#" -ne "1" ]
then
	echo Illegal number of parameters
	exit 1
fi
if [ ! -f $1 ]
then
	echo Input should be file 
	exit 2
fi

awk '{print $0}' RS=' ' $1 |  egrep '^(.)\1{2,}.*$' 
