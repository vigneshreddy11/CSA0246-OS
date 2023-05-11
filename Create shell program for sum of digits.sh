#!/bin/bash

# Read the input from the user
echo "Enter a number:"
read number

# Initialize variables
sum=0
temp=$number

# Calculate the sum of digits
while [ $temp -gt 0 ]; do
  digit=$((temp % 10))
  sum=$((sum + digit))
  temp=$((temp / 10))
done

# Print the sum
echo "The sum of digits in $number is: $sum"
