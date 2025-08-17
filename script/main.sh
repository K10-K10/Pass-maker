#!/bin/zsh

typeset -A test_set
test_set[$1]=1

while IFS= read -r line; do
  [[ -z "$line" ]] && continue
  if [[ -n "${test_set[$line]}" ]]; then
    echo "FOUND: $line"
    exit 1
  fi
done < ../script/rockyou.txt

echo "Not Found"
exit 0
