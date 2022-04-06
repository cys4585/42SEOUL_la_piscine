#!/bin/sh

PASSED_ALL=1

gcc -Wall -Wextra -Werror ft_atoi_base.c main.c -o ./ex05.out
if [ $? -ne 0 ]; then
  echo '[ex05] FAILED - compilation failed'
  PASSED_ALL=0
fi
norminette -R CheckForbiddenSourceHeader ft_atoi_base.c
if [ $? -ne 0 ]; then
  echo '[ex05] FAILED - norminette'
  PASSED_ALL=0
fi
cat ex05-in.txt | xargs -L1 ./ex05.out | diff ex05-out.txt - > null
if [ $? -ne 0 ]; then
  echo '[ex05] FAILED - output differs'
  PASSED_ALL=0
fi

if [ $PASSED_ALL -eq 1 ]; then
  echo '[ex05] PASSED ALL TESTS'
fi
