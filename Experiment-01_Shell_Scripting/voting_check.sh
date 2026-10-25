#!/bin/bash

echo "Enter your age:"
read age

if [ $age -ge 18 ]
then
    echo "You are eligible for voting."
else
    echo "You are not eligible for voting."
fi
