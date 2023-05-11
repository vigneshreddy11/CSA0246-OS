#!/bin/bash

# Function to generate Fibonacci series
fibonacci() {
  num=$1

  # Check if the input is 0 or 1
  if [ $num -eq 0 ]; then
    echo "0"
  elif [ $num -eq 1 ]; then
    echo "0 1"
  else
    a=0
    b=1
    echo -n "0 1"

    # Generate the Fibonacci series up to the given number
    for ((i=2; i<=num; i++)); do
      c=$((a + b))
      echo -n " $c"
      a=$b
      b=$c
    done

    echo "" # Print a new line
  fi
}

# Read the input from the user
echo "Enter the number of terms in the Fibonacci series:"
read n

# Call the fibonacci function with the user input
echo "the fibonacci series is :"
fibonacci $n
