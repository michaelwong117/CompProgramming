#Problem        : Expecto Palindronum
#Language       : Python
#Compiled Using : py_compile
#Version        : Python 2.7.8
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

#from __future__ import print_function
import re
import sys

data = sys.stdin.readlines()

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



for line in data:
    line = re.sub('[^a-zA-Z0-9-_*.]', '', line)
    test_palindrome = line
    length = len(test_palindrome)
    back_add = ""
    while is_palindrome_v1(test_palindrome[:length]) == False:
        back_add = test_palindrome[length-1:]
        print 'back_add =', back_add
        print 'length = ', length
        length = length - 1
    print len(back_add + line)
    
