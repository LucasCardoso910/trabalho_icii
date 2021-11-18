#!/bin/bash

function compare_files() {
    declare -a files
    for i in {1..5}; do
        month="mes_$i"
        files=(output/${month}*)
        
        if [[ $(cmp -s ${files[0]} ${files[1]}) -ne 0 ]]; then
            printf '%s\n' "Ordered files are not equal!"
            return 1
        fi

        if [[ $(cmp -s ${files[1]} ${files[2]}) -ne 0 ]]; then
            printf '%s\n' "Ordered files are not equal!"
            return 1
        fi

        if [[ $(cmp -s ${files[2]} ${files[3]}) -ne 0 ]]; then
            printf '%s\n' "Ordered files are not equal!"
            return 1
        fi

        if [[ $(cmp -s ${files[3]} ${files[4]}) -ne 0 ]]; then
            printf '%s\n' "Ordered files are not equal!"
            return 1
        fi
    done

    return 0
}
