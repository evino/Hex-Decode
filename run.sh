#!/bin/zsh
rm bits
clang++ hexDecode.cpp -o bits -g
./bits in1.txt out1.txt
