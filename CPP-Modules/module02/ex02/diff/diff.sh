#!/bin/bash

diff_result=$(diff diff/myOutput diff/answer)

if [ -z "$diff_result" ]; then
  echo "$(tput setaf 2)Success$(tput sgr0)"
else
  echo "$(tput setaf 1)Failed$(tput sgr0)"
  echo "$(tput setaf 3)****************************************$(tput sgr0)"
  echo "Diff result:"
  echo "$diff_result"
  echo "$(tput setaf 3)****************************************$(tput sgr0)"
fi
