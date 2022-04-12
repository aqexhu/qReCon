#!/bin/bash
check=1
if [ $check -eq 1 ] 
then
	sudo apt install gpiod
fi
for i in {6,13,19,26} ; do echo $i && gpioset -m time -u 2000000 0 $i=1 && sleep 2 ; done
