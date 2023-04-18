# GDB command file
break main.cpp:17
run

# Print a value of variable
print a
print b
print gcd

# Reuse printed value
# a
print $1

# Call function
print GreatestCommonDivisor(b, a)

# Assign a new value
print gcd = 1
print gcd
# GCD is changed, therefore the program will be return wrong result

# Get a pointer address
print &a
# Also pointer dereference can be used

continue

quit
