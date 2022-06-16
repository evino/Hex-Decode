#!/bin/zsh
rm bits
rm out1.txt

ls -laG

clang++ hexDecode.cpp -o bits -g
./bits ./testFiles/in1.txt ./testFiles/out1.txt
