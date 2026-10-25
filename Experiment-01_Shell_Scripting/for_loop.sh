#!/bin/bash

echo "Addition of first 10 numbers:"
sum=0
for i in 1 2 3 4 5 6 7 8 9 10
do
  sum=$((sum + i))
done
echo "Sum: $sum"
