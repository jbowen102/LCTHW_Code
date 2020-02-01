#!/bin/bash

# Number of ex13a arguments to generate is first argument passed from stdin ($1).

ARGS=""

# for (( i=0 ; i < 198220 ; i+=10))
for (( j=0 ; j < 209120 ; j+=10))
do
    ARGS+="0 1 2 3 4 5 6 7 8 9 "
done

for (( i=209120 ; i < 209120+$1 ; i+=1))
do
    ARGS+="1 "
done

printf "Arg count: $i\n"
./ex13a $ARGS
