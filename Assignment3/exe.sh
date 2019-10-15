#!/bin/bash

# judge existence of makefile
if [ -e makefile -o -e Makefile ]  
then
	str=`cat makefile`
	#exe=${str%%\:*}
	#rm -rf ${exe}
else
	echo "No Makefile Error!"
	exit 1
fi

# degrade permission except *.exe, delete all *.exe
chmod -x *.cpp *akefile
if [ -e *.h* ]
then 
	chmod -x *.h*
fi
exe=`find . -type f -perm -700 ! -perm 700`
rm -rf $exe *.o

make
exe=`find . -type f -perm -700 ! -perm 700`
${exe}

