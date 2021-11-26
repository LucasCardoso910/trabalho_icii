#!/bin/bash

declare -gr BLUECOLOR='\033[1;34;49m%s\033[m'
declare -gr REDCOLOR='\033[1;31;49m%s\033[m'
declare -gr YELLOWCOLOR='\033[1;33;49m%s\033[m'
declare -gr GREENCOLOR='\033[1;32;49m%s\033[m'

declare -A expected_results

mkdir .temp
mkdir .temp/data

gcc main.c -o main.out

# Running order tests
for file in order_tests/*.txt; do
    ./main.out < "$file"
    
    for ordered_file in .temp/*.txt; do
        sort -C "$ordered_file"

        if [[ "$?" -ne 0 ]]; then
            printf "$REDCOLOR\n" "Wrong order!"
            printf '%s\n' "While ordering $file, $ordered_file contains wrong results!"
        fi 

        rm "$ordered_file"
    done
done

rm .temp/data/*

for file in data_tests/*.txt; do
    ./main.out < "$file"

    # File is the txt we are working right now
    IFS='/.'
    file=($file)
    filename="${file[1]}"
    file="${file[1]}.${file[2]}"
    unset IFS

    # Getting expected results from the file
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

    # Just like before, it checks if all output files from the c function that
    # are txt files are correctly ordered
    for ordered_file in .temp/*.txt; do
        sort -C "$ordered_file"

        if [[ "$?" -ne 0 ]]; then
            printf "$REDCOLOR\n" "Wrong order!"
            printf '%s\n' "While ordering $file, $ordered_file contains wrong results!"
        fi

        rm "$ordered_file"
    done

    # data_file is the csv file of each function,
    # meaning that it stores the function name
    for data_file in .temp/data/*.csv; do
        results=$(tail -n 1 $data_file) # Get last line in the data file

        # Breaks the line into three diferrent topics:
        # File name (test{x}.txt), comparisons, moves
        IFS=','
        results=($results)
        unset IFS

        # Breaks the file name to get the func name
        IFS='/.'
        func_name=($data_file)
        func_name=${func_name[3]}
        unset IFS

        # Obtains the actual made comparisons and moves
        comparisons=${results[1]}
        moves=${results[2]}

        # Break the string in the dict to get the expected values
        IFS=','
        expected=(${expected_results[$func_name]})
        expected_comparisons="${expected[0]}"
        expected_moves="${expected[1]}"
        unset IFS

        [[ -z "$expected" ]] && rm $data_file && continue

        # Compare these values with the expected values
        if [[ "$comparisons" != "$expected_comparisons" ]]; then
            printf "${REDCOLOR}\n" "Wrong comparisons number!"
            printf "${BLUECOLOR}" "$func_name"
            printf '%s' "$ produced wrong number of comparisons in "
            printf "${BLUECOLOR}\n" "$file"
            printf '%s\n\n' "Produced $comparisons, when expected $expected_comparisons"
        elif [[ "$moves" != "$expected_moves" ]]; then
            printf "${REDCOLOR}\n" "Wrong comparisons number!"
            printf "${BLUECOLOR}" "$func_name"
            printf '%s' " produced wrong number of moves in "
            printf "${BLUECOLOR}\n" "$file"
            printf '%s\n\n' "Produced $moves, when expected $expected_moves"
        fi

        rm $data_file
    done
done

rmdir .temp/data
rmdir .temp