#!/bin/bash

echo "Running vulpTest as `whoami`"

if [[ -e /tmp/XYZ ]]
	then
	echo "/tmp/XYZ exists. Deleting /tmp/XYZ."
	rm -f /tmp/XYZ
fi

while (( 1 == 1 ))
do
	./vulp < payload2.txt
	if [[ -O /tmp/XYZ ]]
		then
		rm -f /tmp/XYZ
	fi	
done
