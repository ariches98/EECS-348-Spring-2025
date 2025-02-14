#!/bin/bash

input="The five boxing wizards jump quickly"

# Question 1: Match "bo", followed by any characters, ending in "ng".
echo "Question1"
echo "$input" | grep -o 'bo.*ng'

# Question 2: Match a four-letter word that doesn’t contain "u".
echo "Question2"
echo "$input" | grep -o '\b[a-zA-Z]{4}\b'

# Question 3: Match three consecutive words, where the middle word begins with "b".
echo "Question3"
echo "$input" | grep -o '\b\w+\s+b\w+\s+\w+\b'

# Question 4: Identify all function declarations (including parameters)
echo "Question4"
grep -E '\w+\s+\w+\(.*\)\s*{' code.c

# Question 5: Extract lines where a C structure is defined using awk
echo "Question5"
awk '/struct [A-Za-z_]+ {/' code.c

# Question 6: Replace "marks" with "score" in the code using sed
echo "Question6"
sed -e 's/\bmarks\b/score/g' code.c

# Question 7: Find lines where a function is defined with at least two arguments
echo "Question7"
grep -E '\w+\s+\w+\(.*?,.*?\)\s*{' code.c

# Question 8: Identify lines with preprocessor directives using grep
echo "Question8"
grep '^#\w+' code.c

# Question 9: Count the total number of lines that contain function declarations or definitions
echo "Question9"
grep -c '\w+\s+\w+\(.*\)\s*{' code.c

# Question 10: Extract and list all unique function names using grep and cut
echo "Question10"
grep -Po '^\w+ \K\w+(?=\()' code.c | sort -u
