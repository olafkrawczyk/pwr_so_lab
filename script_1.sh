#!/bin/bash

echo Passed directory: $1

for file in "$1"/*.old 
do
  if [ -f "$file" ]
    then
      echo Removing file: $file
      rm $file
    fi
done

for file in "$1"/* 
do
  if [ -f "$file" ]
    then
      echo Renaming file: $file to $file.old
      mv $file $file.old
    fi
done

