#!/bin/bash

function format_files()
{
  ## Format C files
  clang-format -i "src/library.h" 2> /dev/null

  for file in src/search/methods/*; do
    clang-format -i "$file" 2> /dev/null
  done
  clang-format -i src/search/main.* 2> /dev/null

  for file in src/sorting/methods/*; do
    clang-format -i "$file" 2> /dev/null
  done
  clang-format -i src/sorting/main.* 2> /dev/null

  ## Format Python files
  black data/data_generator.py 2> /dev/null

  ## Format Bash files
  for file in etc/*.sh; do
    shfmt -w -i=2 -ln=bash -fn -ci -sr "$file" 2> /dev/null
  done
  shfmt -w -i=2 -ln=bash -fn -ci -sr run1 run2 2> /dev/null
}
