#!/bin/sh

echo "Enter first number:"
read num1

echo "Enter second number:"
read num2

echo "Menu"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

echo "Enter your choice:"
read choice

case $choice in
1)
    echo "Addition = $((num1 + num2))"
    ;;
2)
    echo "Subtraction = $((num1 - num2))"
    ;;
3)
    echo "Multiplication = $((num1 * num2))"
    ;;
4)
    echo "Division = $((num1 / num2))"
    ;;
*)
    echo "Invalid Choice"
    ;;
esac
