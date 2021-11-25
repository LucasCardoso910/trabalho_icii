#!/bin/bash

function compare()
{
  declare -a files
  local non_sorted_files=0

  for i in {1..5}; do
    month="mes_$i"

    for file in "output/sorting/$month"/*; do
      sort -C "$file"

      if [[ $? -ne 0 ]]; then
        printf '%s\n' "$i $file"
        non_sorted_files=$(($non_sorted_files + 1))
      fi
    done
  done

  if [[ $non_sorted_files -eq 0 ]]; then
    printf '%s' '0'
  fi

  return 0
}
