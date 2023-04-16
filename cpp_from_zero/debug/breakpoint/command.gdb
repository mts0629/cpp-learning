# GDB command file

# Create break points
# Source:line #
break main.cpp:6
# Symbol
break Sum

# Show breakpoints
info breakpoints

# Run
run

# Delete a break point #1
info breakpoints
delete 1
info breakpoints

# Delete all break points
delete breakpoints
info breakpoints

# Continue from the break point
continue

# Quit GDB
quit
