def reverse(s):
    rev = ''
    for ch in s:
        rev = ch + rev

    return rev

def if_palindrome(x):
    string_num = str(x)

    return reverse(string_num) == string_num


      
print(if_palindrome(101))      
print(if_palindrome(123))
print(if_palindrome(1771))
print(reverse('hello'))
      




    
