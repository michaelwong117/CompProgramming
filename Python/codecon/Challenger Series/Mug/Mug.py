#Problem        : Mug Color
#Language       : Python
#Compiled Using : py_compile
#Version        : Python 2.7.8
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

#from __future__ import print_function
import re
import sys

data = sys.stdin.readlines()
mug_colors = ["Yellow", "Red", "Black", "Blue", "White"]
for line in data:
    line = re.sub('[^a-zA-Z0-9-_*.]', '', line)
    if line == "Yellow" and line in mug_colors:
        mug_colors.remove("Yellow")
    elif line == "Red" and line in mug_colors:
        mug_colors.remove("Red")
    elif line == "Blue"  and line in mug_colors:
        mug_colors.remove("Blue")
    elif line == "Black"  and line in mug_colors:
        mug_colors.remove("Black")
    elif line == "White"  and line in mug_colors:
        mug_colors.remove("White")

print mug_colors[0]
     
   

