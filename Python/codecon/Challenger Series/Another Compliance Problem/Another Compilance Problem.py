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

#sees whether or not the histogram of the word is a palindrome
def histogram_p(word):
    count = 0
    count2 = 0
    hist = histogram(word)
    for k,v in hist.iteritems():
        if v == 1:
            count += 1
        if v % 2 != 0:
            count2 += 1
        if count >= 2 or count2 >= 2:
            return False
    if hist:
        return True
    else:
        return False

def fact(n):
    answer1 = 1
    for i in range(1, n+1):
        answer1 = answer1 * i
    return answer1

#returns the number of anagrams of the word that are also palindromes
def anagram_p(word):
    sum = 0
    h = histogram(word)
    #print h
    if histogram_p(word) == True:
        # Can form one or more palindromes.
        for k,v in h.iteritems():
            sum += (v // 2)
        sum = fact(sum)
        #print '1. sum = ', sum
        for k,v in h.iteritems():
            sum = sum / fact(v // 2)
        return sum

    else:
        return 0


import sys
import re
data = sys.stdin.readlines()
for line in data:
    line = re.sub('[^a-z]+', '', line)
    print anagram_p(line)








