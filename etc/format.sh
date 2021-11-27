#!/bin/bash

function format_files()
{
  ## Format C files
  clang-format -i "src/library.h"

  for file in src/search/methods/*; do
    clang-format -i "$file"
  done
  clang-format -i src/search/main.*

  for file in src/sorting/methods/*; do
    clang-format -i "$file"
  done
  clang-format -i src/sorting/main.*

  ## Format Python files
  black data/data_generator.py 2> /dev/null

  ## Format Bash files
  for file in etc/*.sh; do
    shfmt -w -i=2 -ln=bash -fn -ci -sr "$file"
  done
  shfmt -w -i=2 -ln=bash -fn -ci -sr run1 run2
}
