#!/bin/bash

function translate()
{
    number=$1

    if [[ $number -eq $BUBBLE ]]; then
        printf '%s' 'Bubble sort'
        return 0
    elif [[ $number -eq $INSERT_BIN ]]; then
        printf '%s' 'Insert binary sort'
        return 0
    elif [[ $number -eq $INSERT ]]; then
        printf '%s' 'Insert sort'
        return 0
    elif [[ $number -eq $SELECTION ]]; then
        printf '%s' 'Selection sort'
        return 0
    fi

    printf '%s' 'null'
    return 1
}