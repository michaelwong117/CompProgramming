##Assignment 3, Due by 5PM on Friday, February 19:
##
##The third homework assignment is to write a Python function which
##accepts two strings as arguments and returns the longest sub-string
##(contiguous characters) that they have in common. For example, if
##the first string were "abcdefghijk" and the second string were
##"zzjskasbcdjkm", then your function would return the value "bcd".
##Note that the strings also have the strings "a", "j", "b", "c", "d",
##"k"and "jk" in common, but all are shorter than "bcd". If there are
##several different common strings of the same longerst length, you
##may just return one of them, presumably the first you find. Note
##that the matching sub-strings do not have to be in the same
##positions in both strings and the two argument strings do not have
##to be of the same length. If there is no common sub-string, your
##function should return the empty string, "".
##
##Hints: Of course you will use the function, find, which we wrote in
##class on February 4 and which you will use in section the week of
##February 16. I would proceed by slicing strings of shorter and
##shorter length out of the first argument string, starting with the
##whole string, and trying to find them in the second. I hope that
##hint doesn't take too much fun out of the assignment for you. You
##still have to figure out how to get ALL of the sub-strings of a
##given length. This is an exercise in nested loops (one within
##another) and in choosing the limits of the slice operations on
##sequences. Do NOT use the functions in the Python library string
##module. They can become part of your repertoire after the midterm
##exam. The find function from Feb 4 lecture is OK to use.
##
##As with assignment 2, when you have a working function saved with
##the name yourlastnamehw3.py, eg. smithhw3.py, upload it to the
##assignment 3 dropbox for your TF.

def sub_string(s):
    string_list = []
    for i in range(0, len(s)):
        for i2 in range(1, len(s)+1):
            string_list.append(s[i:i2])
            
    return string_list
                               
                        
                           
                           
print(sub_string("abc"))      
print(sub_string("1234"))
        

def longest_common(s1, s2):
    longest = ''
    a = sub_string(s1)
    b = sub_string(s2)
    for phrase1 in a:
        for phrase2 in b:
            if len(phrase1) > len(longest):
                if phrase1 == phrase2:
                    longest = phrase1
    return longest

# Should return "ajk".               
print(longest_common("ajkloc", "ajkdff"))

# Should return "abc".
print(longest_common("1234abc5", "1abc12"))

# Should return "abcd".
print(longest_common("aaabcdabc", "1234abcd"))
