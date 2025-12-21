#!/bin/bash

source ./solution.sh
read_input_to_array "input.txt"
value=50
count=0
#echo "VALUE: ${value}"
for var in "${VALUE_ARRAYS[@]}"; do
    (( var = var % 100))
    (( value+="${var}" ))
    if (( value > 99 )); then
        ((value-=100))
    elif (( value < 0 )); then
        (( value += 100 ))
    fi
    #echo "VAR AFTER: ${var}"
    #echo "VALUE after: ${value}"
    if (( value==0 )); then
        (( count+= 1 ))
    fi
done

echo "COUNT: ${count}"
