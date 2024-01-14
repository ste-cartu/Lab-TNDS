#!/bin/bash

#chmod 777 myscript.sh



touch indirizzi.dat;
find . -type f -name 'media*' | awk -F\/ '{print $2}' | sort -n > indirizzi.dat; #chmod 777 indirizzi.dat;
echo 0 >> indirizzi.dat;
find . -type f -name 'hitmiss*' | awk -F\/ '{print $2}' | sort -n >> indirizzi.dat;
