#!/bin/bash

# Read the input from the user
echo "Enter the value of n:"
read n

sum=0

# Read n numbers from the user and calculate their sum
for ((i=1; i<=n; i++)); do
  echo "Enter number $i:"
  read num
  sum=$((sum + num))
done

# Print the sum
echo "The sum of the $n numbers is: $sum"
