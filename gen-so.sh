#!/bin/bash
rm *.out *.so *.o *.oct

if [[ -z "$*"  ]];
then 
	echo 'Warning: Correct usage ./gen-so.sh <filename>'
	set -- "fun"
fi

#The $1 is the filename that can be passed as an argument to this file. Default is 'fun'

mkoctfile -fPIC $1.cpp
g++ -shared -o lib$1.so $1.o
g++ -Wall -o test main.cpp -l$1


#mkoctfile -fPIC --link-stand-alone $1.cpp -o $1.out
#gcc $1.o -shared -o lib$1.so


#sudo cp libfun.so /usr/lib
#sudo /sbin/ldconfig
#g++ -shared -o lib$1.so $1.o
#g++ -L$(pwd) -Wl,-rpath=$(pwd) -Wall -o oct main.cpp -l$1

