#!/bin/bash

g++ "URI-$1.cpp" -o "URI-$1" -std=c++11

./URI-$1 < files/input > files/output
diff -s verificacao/output verificacao/answers

rm -f "URI-$1"

