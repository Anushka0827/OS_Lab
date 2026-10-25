#!/bin/bash

echo "Enter a number:"
read num

case $num in 
1) echo "One";;
2) echo "Two";;
3) echo "Three";;
4) echo "Four";;
*) echo "Number is greater than four";;
esac
