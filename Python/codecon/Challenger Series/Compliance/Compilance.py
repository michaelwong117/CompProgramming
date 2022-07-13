
def is_palindrome_v1(s):
    """ (str) -> bool

    Return True if and only if s is a palindrome.

    >>> is_palindrome_v1('noon')
    True
    >>> is_palindrome_v1('racecar')
    True
    >>> is_palindrome_v1('dented')
    False
    """

    return reverse(s) == s


def reverse(s):
    """ (str) -> str

    Return a reversed version of s.

    >>> reverse('hello')
    'olleh'
    >>> reverse('a')
    'a'
    """

    rev = ''

    # For each character in s, add that char to the beginning of rev.
    for ch in s:
        rev = ch + rev

    return rev

def histogram(word):
    a = {}
    for char in word:
        if char in a:
            a[char] += 1
        else:
            a[char] = 1
    return a
#from __future__ import print_function
def histogram_p(word):
    count = 0
    count2 = 0
    for key in histogram(word):
        if histogram(word)[key] == 1:
            count += 1
        if histogram(word)[key] % 2 != 0:
            count2 += 1
        if count >= 2 or count2 >= 2:
            return False
    return True

import sys
import re
data = sys.stdin.readlines()
for line in data:
    line = re.sub('[^a-zA-Z0-9-_*. ]', '', line)
    if histogram_p(line) == True:
        print("yes")
    else:
        print("no")












        
        
            








    
