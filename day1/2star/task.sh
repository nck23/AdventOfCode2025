#!/bin/bash

source ./solution.sh
read_input_to_array "input.txt"
value=50
count=0
for var in "${VALUE_ARRAYS[@]}"; do
    (( old_count = count ))
    echo "OLD count: ${old_count}"
    echo "${value}"
    (( old_val = value ))
    temp_var=$(( var < 0 ? -var : var))
    if [[ "${var:0:1}" == "-" ]]; then
        echo "L${temp_var}"
    else
        echo "R${temp_var}"
    fi
    (( count += temp_var / 100 )) # hundreds and thousands
    (( value += var % 100 ))
    if (( value > 99 )); then
        (( value -= 100 ))
        (( count += 1 ))
    elif (( value < 0)); then
        (( value += 100 ))
        if (( old_val != 0)); then
            (( count += 1 ))
        fi
    elif (( value == 0 && old_val != 0 )); then
        (( count += 1 ))
    fi
    echo "${value}"
    if (( old_count != count )); then
        echo "NEW count: ${count}"
    fi
    echo ""
done

echo "COUNT: ${count}"
