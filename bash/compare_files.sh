#!/bin/bash

function compare()
{
  declare -a files
  for i in {1..5}; do
    month="mes_$i"
    files=(output/${month}*)

    cmp -s ${files[$BUBBLE]} ${files[$INSERT_BIN]}
    if [[ $? -ne 0 ]]; then
      printf '%s' "$i $BUBBLE $INSERT_BIN"
      return 1
    fi

    cmp -s ${files[$INSERT_BIN]} ${files[$INSERT]}
    if [[ $? -ne 0 ]]; then
      printf '%s' "$i $INSERT_BIN $INSERT"
      return 1
    fi

    cmp -s ${files[$INSERT]} ${files[$SELECTION]}
    if [[ $? -ne 0 ]]; then
      printf '%s' "$i $INSERT $SELECTION"
      return 1
    fi
  done

  printf '%s' '0'
  return 0
}
