#!/bin/bash

read_input_to_array() {
    VALUE_ARRAYS=()
    local file_path=$1
    if [[ ! -f "$file_path" ]]; then
        echo "Błąd: Plik $file_path nie istnieje!"
        return 1
    fi
    readarray -t INPUT_DATA < "$file_path"
    for line in "${INPUT_DATA[@]}"; do 
        case "${line:0:1}" in
        "L")
            VALUE_ARRAYS+=("-${line:1}")
            ;;
        "R")
            VALUE_ARRAYS+=("${line:1}")
            ;;
        esac
    done
}