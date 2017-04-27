#Olaf Krawczyk 218164 27.04.2017
# W zadanym katalogu znalezc pliki wykonywalne do ktorych wykonujacy skrpyt ma prawo wykonania,
# prawo wykonania wlasciciela jest zablokowane, a dla grupy jest ustalone
import os
import sys
import stat

if len(sys.argv) != 2:
    print "Niepoprawna liczba argumentow"
    print "Podaj jedynie sciezke do katalogu"
    sys.exit(1)
if not os.path.isdir(sys.argv[1]):
    print "Argument musi byc katalogiem!"
    sys.exit(1)

files = os.listdir(sys.argv[1])

for file in files:
    path = os.path.join(sys.argv[1], file)
    if os.path.isfile(path) and os.access(path, os.X_OK):
        st = os.stat(path)
        if not bool(st.st_mode & stat.S_IXUSR) and bool(st.st_mode & stat.S_IXGRP):
            print path
