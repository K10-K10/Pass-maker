#!/bin/zsh

typeset -A test_set
test_set[$1]=1

while IFS= read -r line; do
  [[ -z "$line" ]] && continue
  if [[ -n "${test_set[$line]}" ]]; then
    echo -e "\e[31mX\e[0m"
    exit 1
  fi
done < ../script/rockyou.txt

echo "\e[32mO\e[0m"
exit 0
