#!/bin/zsh

typeset -A test_set
test_set[$1]=1

while IFS= read -r line; do
  [[ -z "$line" ]] && continue
  if [[ -n "${test_set[$line]}" ]]; then
    exit 1
  fi
done < ../script/rockyou.txt

exit 0
