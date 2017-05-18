#Olaf Krawczyk 218164 18.05.2017
#Z zadanego programu w C wyciagnac wszystkie komentarze
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
if not sys.argv[1].split(".")[-1] == "c":
    print "Plik musi byc programem w C (xx.c)"
    sys.exit(1)


with open(sys.argv[1], 'r') as f:
    file = f.read()
    match = re.findall(r"(/\*(.|[\r\n])*?\*/)|(//.*$)",  file, re.MULTILINE)
    for m in match:
        if m[0]:
            print m[0]
        else:
            print m[-1]
