#!/bin/bash
check=0
if [ $check -eq 1 ] 
then
	sudo apt install gpiod
fi
#old v1.0, v1.1
#for i in {6,13,19,26} ; do echo $i && gpioset -m time -u 50000 0 $i=1 && sleep .25 && gpioset 0 $i=0 && sleep 0.25; done
#new v2.2 B1
for i in {5,16,20,21} ; do echo $i && gpioset -m time -u 50000 0 $i=1 && sleep .25 && gpioset 0 $i=0 && sleep 0.25; done
#new v2.2 B2
#for i in {6,13,19,26} ; do echo $i && gpioset -m time -u 50000 0 $i=1 && sleep .25 && gpioset 0 $i=0 && sleep 0.25; done
