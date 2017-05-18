#Olaf Krawczyk 218164 18.05.2017
# W zadanym pliku tekstowym znalezc wszystkie slowa ktore maja pierwsze trzy litery takie same
import os
import sys
import re


if len(sys.argv) != 2:
    print "Niepoprawna liczba argumentow"
    print "Podaj jedynie sciezke do pliku"
    sys.exit(1)
if not os.path.isfile(sys.argv[1]):
    print "Argument musi byc plikiem!"
    sys.exit(1)


with open(sys.argv[1], 'r') as f:
    file = f.readlines()
    for line in file:
        for word in line.split(" "):
            match = re.findall(r"(^([A-Za-z])\2{2,}\w*\s*)", word)
            if match:
                print match[0][0]
