#!/bin/bash

# Prompt the user to enter a number
echo "Enter a number: "
read number

# Initialize fact to 1
fact=1

# Loop to calculate the factorial
for (( i = 1; i <= number; i++ )); do
    fact=$(( fact * i ))  # Perform the multiplication
done

# Output the result
echo "Factorial of $number is $fact"
