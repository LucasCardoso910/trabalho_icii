#!/bin/bash

declare -A expected_results
declare -A errors_by_function

declare comparisons
declare moves
declare expected_comparisons
declare expected_moves

# it checks if all output files from the c function
# that are txt files are correctly ordered
function check_order_in()
{
  local file="$1"
  local folder="$2"
  local delete="$3"
  local errors=0

  for ordered_file in "$folder"/*.txt; do
    sort -C "$ordered_file"

    if [[ "$?" -ne 0 ]]; then
      printf "$REDCOLOR\n" "Wrong order!"
      printf '%s\n' "While ordering $file, $ordered_file contains wrong results!"
      errors=$(($errors + 1))
    fi

    [[ -n $delete ]] && rm "$ordered_file"
  done

  return $errors
}

function order_tests()
{
  local errors=0

  printf "$BLUECOLOR\n" 'Running test [order_tests]'
  printf "$BLUECOLOR\n" "$SEPARATOR"

  for file in order_tests/*.txt; do
    printf '%s\n' "$file"

    ./main.out < "$file"
    check_order_in $file ".temp" "DELETE!"
    errors=$(($errors + $?))
  done

  if [[ $errors -eq 0 ]]; then
    printf "$GREENCOLOR\n" "Sorting OK"
  fi
  printf '\n'

  # Removing unused data files
  rm .temp/data/*
}

function get_test_file()
{
  local file="$1"

  IFS='/.'
  file=($file)
  filename="${file[1]}"
  file="${file[1]}.${file[2]}"
  unset IFS

  printf '%s' "$file"
}

# Getting expected results from the file
function read_expected_for()
{
  local file="$1"

  while read line; do
    IFS=':,'
    line=($line)
    expected_results["${line[0]}"]="${line[1]},${line[2]}"
    unset IFS

    # line[0] is the name of function and it is the key in the dict
    # line[1] is the number of comparisons made by this function in this file
    # line[2] is the number of moves made by this function in this file
    # Example: expected_results["insert_sort"]="21,12"
    # We can get the numbers later by setting the IFS to commas.
  done < "data_tests/expected/$file"
}

function get_results()
{
  data_file="$1"

  results=$(tail -n 1 $data_file) # Get last line in the data file

  # Breaks the line into three diferrent topics:
  # File name (test{x}.txt), comparisons, moves
  IFS=','
  results=($results)
  unset IFS

  # Obtains the actual made comparisons and moves
  comparisons=${results[1]}
  moves=${results[2]}
}

function get_func_name_from()
{
  local data_file="$1"

  IFS='/.'
  func_name=($data_file)
  func_name=${func_name[3]}
  unset IFS

  printf '%s' "$func_name"
}

# Break the string in the dict to get the expected values
function get_expected_results()
{
  local func_name="$1"

  IFS=','
  expected=(${expected_results["$func_name"]})
  expected_comparisons="${expected[0]}"
  expected_moves="${expected[1]}"
  unset IFS
}

function data_tests()
{
  printf "$BLUECOLOR\n" 'Running test [data_tests]'
  printf "$BLUECOLOR\n" "$SEPARATOR"

  for file in data_tests/*.txt; do
    printf '%s\n' "$file"
    ./main.out < "$file"

    file=$(get_test_file "$file")
    read_expected_for "$file"
    check_order_in $file ".temp" "DELETE!"

    # data_file is the csv file of each function,
    # meaning that it stores the function name
    for data_file in .temp/data/*.csv; do
      get_results "$data_file"
      func_name=$(get_func_name_from $data_file)

      # Set associative array of errors with the func_name as key and -1 as
      # value. This is used to assert which functions performed with success
      errors_by_function["$func_name"]=0

      get_expected_results "$func_name"

      [[ -z "$expected" ]] && rm $data_file && continue

      # Compare these values with the expected values
      if [[ "$comparisons" != "$expected_comparisons" ]]; then
        printf "\n$YELLOWCOLOR\n" "Warning: Wrong comparisons number!"
        printf "$BLUECOLOR" "$func_name"
        printf '%s' " produced wrong number of comparisons in "
        printf "$BLUECOLOR\n" "$file"
        printf '%s\n\n' "Produced $comparisons, but expected $expected_comparisons"
        errors_by_function["$func_name"]=$((${errors_by_function["$func_name"]} + 1))
      fi

      if [[ "$moves" != "$expected_moves" ]]; then
        printf "\n$YELLOWCOLOR\n" "Warning: Wrong movimentations number!"
        printf "$BLUECOLOR" "$func_name"
        printf '%s' " produced wrong number of moves in "
        printf "$BLUECOLOR\n" "$file"
        printf '%s\n\n' "Produced $moves, but expected $expected_moves"
        errors_by_function["$func_name"]=$((${errors_by_function["$func_name"]} + 1))
      fi

      rm $data_file
    done
  done

  for func_name in "${!errors_by_function[@]}"; do
    if [[ "${errors_by_function[$func_name]}" -eq 0 ]]; then
      printf "$func_name $GREENCOLOR\n" "OK"
    fi
  done
}

function perform_tests()
{
  cd tests
  mkdir .temp
  mkdir .temp/data

  gcc main.c -o main.out

  order_tests
  data_tests

  rmdir .temp/data
  rmdir .temp
}
