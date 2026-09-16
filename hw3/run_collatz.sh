#!/bin/bash

max_length=0 #/start with 0 values and change them if we come accross a higher val
max_start=0 

for var in $(cat input_values) ; do # for loop that goes through file created with int 1-1000

    length=$( echo $var | ./collatz) #calls collatz function and gives it to var 

    if [ $length -gt $max_length ] ; then #if value from collatz is greater than max_length it will update value 

	max_length=$length
	max_start=$var

	echo "The new max length is $max_length and the start is $max_start"

    fi
done

echo "The longest seequence: start=$max_start, length=$max_length" 
    
#print final longest numnber 
