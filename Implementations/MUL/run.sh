#!/bin/bash
message="spliter"
compiler=gcc
commonFlags="-D _GNU_SOURCE -Ofast -march=native"
novecFlags="-fno-tree-vectorize -fno-tree-slp-vectorize"
pox=.c
echo
echo $message>>fileForOutPuts
echo "Time: $(date)">>fileForOutPuts
echo $compiler >>fileForOutPuts
echo $commonFlags>>fileForOutPuts
echo $novecFlags>>fileForOutPuts

file="IMP3"
$compiler $commonFlags $novecFlags   $file$pox -o $file$cmp && ./$file$cmp
