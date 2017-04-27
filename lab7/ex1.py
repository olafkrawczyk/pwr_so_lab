#Olaf Krawczyk 218164 27.04.2017
# W zadanym katalogu zamienic wszystkie dowiazania twarte do plikow w tym katalogu na symboliczne

import os
import sys

if len(sys.argv) != 2:
    print "Niepoprawna liczba argumentow"
    print "Podaj jedynie sciezke do katalogu"
    sys.exit(1)
if not os.path.isdir(sys.argv[1]):
    print "Argument musi byc katalogiem!"
    sys.exit(1)

files = os.listdir(sys.argv[1])

checked_inodes = dict()

for file in files:
    path = os.path.join(sys.argv[1], file)
    if os.path.isfile(path):
        inode = os.stat(path).st_ino
        if inode not in checked_inodes.keys():
            checked_inodes[inode] = path
            print "Dodanie inode do listy: " + str(inode)
        else:
            os.remove(path)
            os.symlink(checked_inodes[inode].split('\\')[-1], path)
            print "Zmiana hardlink na symlink: " + str(inode)
    else:
        print "Nie plik " + file
