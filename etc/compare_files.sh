#!/bin/bash

. etc/run_tests.sh

function compare()
{
  local non_sorted_files=0

  for i in {1..5}; do
    month="mes_$i"

    message=$(check_order_in "$month" "output/sorting/$month")
    non_sorted_files=$(($non_sorted_files + $?))
    [[ -n "$message" ]] && printf '%s\n' "$message"
  done

  if [[ $non_sorted_files -eq 0 ]]; then
    printf '%s' '0'
  fi

  return 0
}
