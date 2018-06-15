#!/bin/sh

yacc -o expr.c expr.y
/usr/local/bin/clang -fsanitize=fuzzer,undefined,address -g -O0 -o expr expr.c -DENABLE_FUZZER
