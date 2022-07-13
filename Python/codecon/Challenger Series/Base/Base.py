#Problem        : Base Arithmetic
#Language       : Python
#Compiled Using : py_compile
#Version        : Python 2.7.8
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

#from __future__ import print_function
import sys
import re
data = sys.stdin.readlines()
total = 0

def get_base(num):
    base = 0
    for i in line:
        if "F" in str(line):
            base = 16
        elif "E" in str(line):
            base = 15
        elif "D" in str(line):
            base = 14
        elif "C" in str(line):
            base = 13
        elif "B" in str(line):
            base = 12
        elif "A" in str(line):
            base = 11
        elif "9" in str(line):
            base = 10
        elif "8" in str(line):
            base = 9
        elif "7" in str(line):
            base = 8
        elif "6" in str(line):
            base = 7
        elif "5" in str(line):
            base = 6
        elif "4" in str(line):
            base = 5
        elif "3" in str(line):
            base = 4
        elif "2" in str(line):
            base = 3
        elif "1" in str(line):
            base = 2
        elif "0" in str(line):
            base = 1
    return base

def process(num):
    processed = 0
    count = len(str(num)) - 1
    base = get_base(str(num))
    for i in str(num):
        if i == "A":
            i = 10
        if i == "B":
            i = 11
        if i == "C":
            i = 12
        if i == "D":
            i = 13
        if i == "E":
            i = 14
        if i == "F":
            i = 15
            
        processed += int(i) * base**count
        count -= 1
    return processed
        
    
for line in data:
    line = re.sub('[^a-zA-Z0-9-_*.]', '', line)
    total += int(process(line))
print total
        









