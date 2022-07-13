
# Assignment 2, Due by 5PM on Friday, February 12:

# Computer scientists rival bureaucrats in their fondness for acronyms, replacing each word of the name of something by its first letter. Write a Python function which accepts a string as an argument and returns its acronym. You may assume that only space characters are used as separators, but don't forget the first word. For example, if your program is defined with the name, acro, then running it in IDLE would produce a dialog likes this:

# >>>acro("International Business Machines")
# "IBM"
# >>>
# or

# >>>acro("Federal Bureau of Investigation")
# "FBoI"
# >>>
# You may want to have your include only include capital first letters in the output, so that the latter example would return FBI. To see how to do this, try comparing some upper and lower case letters, eg. "a">"Z" and "A">"z". Prepare your function in a module as a .py file using IDLE, or in a word processor if you are using the command line interpreter, and save it as ?????hw2.py, where ????? is your last name. Also, include your name as a comment (after a #) in the first line of the file. Execute it as demonstrated in class and fix any syntactic and logical errors that you find.

# This is a very simple program. If you find yourself spending more than an hour on it, you have missed something in the lectures this week (February 2-4). Go over the tutorial reading and lecture web pages again and/or get in touch with your TF.

# When your program works to your satisfaction, upload the file to the dropbox set up for your TF and this assignment. The drop boxes can be reached by the "Homework dropboxes" among the navigation links on the main course web page. You must upload it no later than the due date and time.


def acronym(s):
    acronym = ""
    for char in s:
        if char == " ":
            pass
        elif char.upper() == char:
            acronym += char
    return acronym
            
            
    
print(acronym("International Business Machines"))
      
print(acronym("Federal Bureau of Investigation"))
      
print(acronym("International House of Pancakes"))
