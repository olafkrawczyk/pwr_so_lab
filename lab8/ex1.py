#Olaf Krawczyk 218164 04.05.2017
# W zadanym drzewie katalogow znalezc dow. sym (wskazujace na pliki reg.) o nazwie takiej jak wsk. plik. reg.
import os
import sys

if len(sys.argv) != 2:
    print "Niepoprawna liczba argumentow"
    print "Podaj jedynie sciezke do katalogu"
    sys.exit(1)
if not os.path.isdir(sys.argv[1]):
    print "Argument musi byc katalogiem!"
    sys.exit(1)

for basepath, dirs, files in os.walk(sys.argv[1]):
    for file in files:
        path = os.path.join(basepath, file)
        if os.path.islink(path):
            file_path = os.path.realpath(path)
            if os.path.split(file_path)[-1] == file:
                print path
