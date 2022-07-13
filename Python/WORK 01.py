Python 3.3.0 (v3.3.0:bd8afb90ebf2, Sep 29 2012, 01:25:11) 
[GCC 4.2.1 (Apple Inc. build 5666) (dot 3)] on darwin
Type "copyright", "credits" or "license()" for more information.
>>> 
5
>>> 7-2
5
>>> 5*2
10
>>> 10% of 100
SyntaxError: invalid syntax
>>> 2**5
32
>>> 4/2
2.0
>>> 4//2
2
>>> 6//2
3
>>> 7//2
3
>>> 7/2
3.5
>>> 2/3
0.6666666666666666
>>> 2//3
0
>>> 5//2
2
>>> 6/1.2
5.0
>>> 2000/546.23
3.6614612892005196
>>> 2000//546.23
3.0
>>> 4%2
0
>>> 2%3
2
>>> 5%3
2
>>> 7%3
1
>>> 3+4-5*2-6+47/2
14.5
>>> -10
-10
>>> "WOW"
'WOW'
>>> 2*"daddy is sooooo fat
SyntaxError: EOL while scanning string literal
>>> a=7
>>> a*5
35
>>> b+8=10
SyntaxError: can't assign to operator
>>> b+8=12

>>> -10 * (3+5)**3
-5120
>>> (70 -305 +32)*(23*54-1117)
-25375

>>> 0/4
0.0
>>> "100 bottles of coke on the wall" * 7
'100 bottles of coke on the wall100 bottles of coke on the wall100 bottles of coke on the wall100 bottles of coke on the wall100 bottles of coke on the wall100 bottles of coke on the wall100 bottles of coke on the wall'
>>> "100 bottles of coke on the wall  " * 7
'100 bottles of coke on the wall  100 bottles of coke on the wall  100 bottles of coke on the wall  100 bottles of coke on the wall  100 bottles of coke on the wall  100 bottles of coke on the wall  100 bottles of coke on the wall  '
>>>  "coke"-"coke"
 

>>> "dan dan bucha dan dan bucha bucha yah, dan dan buchaaaaa"
'dan dan bucha dan dan bucha bucha yah, dan dan buchaaaaa'
>>> max(7,6,4,3.3,2)
7
>>> ax+bx-c=0

>>> ax=bx-c
Traceback (most recent call last):
  File "<pyshell#37>", line 1, in <module>
    ax=bx-c
NameError: name 'bx' is not defined
>>> max (1,2,5,7,45,6,3,2,1,3.141516171819171819117181)
45
>>> dir(_builitins_)
Traceback (most recent call last):
  File "<pyshell#39>", line 1, in <module>
    dir(_builitins_)
NameError: name '_builitins_' is not defined
>>> dir(_builtins_)
Traceback (most recent call last):
  File "<pyshell#40>", line 1, in <module>
    dir(_builtins_)
NameError: name '_builtins_' is not defined
>>> help(abs)
Help on built-in function abs in module builtins:

abs(...)
    abs(number) -> number
    
    Return the absolute value of the argument.

>>> abs(-6)
6
>>> abs(26.23789875-463748628+3687168941846891)
3687168478098289.0
>>> help (pow)
Help on built-in function pow in module builtins:

pow(...)
    pow(x, y[, z]) -> number
    
    With two arguments, equivalent to x**y.  With three arguments,
    equivalent to (x**y) % z, but may be more efficient (e.g. for longs).

>>> "POW!SOCK!BAM!THWOP!CRACK!THUNK!SMACK!WHAM!"
'POW!SOCK!BAM!THWOP!CRACK!THUNK!SMACK!WHAM!'
>>> pow(7,8,3,4,5
    )
Traceback (most recent call last):
  File "<pyshell#47>", line 1, in <module>
    pow(7,8,3,4,5
TypeError: pow expected at most 3 arguments, got 5
>>> pow(6,6,6)
0
>>> pow(4,2
    )
16
>>> f(x)=(x**2/23)+117

>>> def f(x):
	return x-7
f(2)

4
>>> def r(x):
	return x * 2

>>> f(3)
Traceback (most recent call last):
  File "<pyshell#59>", line 1, in <module>
    f(3)
NameError: name 'f' is not defined
>>> r(3)
6
>>> def f(x)

>>> def f(x):
	return x - 7
f(3)

>>> f(3)
Traceback (most recent call last):
  File "<pyshell#65>", line 1, in <module>
    f(3)
NameError: name 'f' is not defined
>>> def area(base,height):
	return base * height /2
area (3,4)
SyntaxError: invalid syntax
>>> area(3,4)
Traceback (most recent call last):
  File "<pyshell#69>", line 1, in <module>
    area(3,4)
NameError: name 'area' is not defined
>>> def area
SyntaxError: invalid syntax
>>> def area(base, height):
	return base*height/2
def area
SyntaxError: invalid syntax
>>> def(area)
SyntaxError: invalid syntax
>>> area(3, 4)
Traceback (most recent call last):
  File "<pyshell#75>", line 1, in <module>
    area(3, 4)
NameError: name 'area' is not defined
>>> def triarea(base, height):
	return base*height/2

>>> area(3,4)
Traceback (most recent call last):
  File "<pyshell#79>", line 1, in <module>
    area(3,4)
NameError: name 'area' is not defined
>>> help (_bulitin_)
Traceback (most recent call last):
  File "<pyshell#80>", line 1, in <module>
    help (_bulitin_)
NameError: name '_bulitin_' is not defined
>>> help (_builtins_)
Traceback (most recent call last):
  File "<pyshell#81>", line 1, in <module>
    help (_builtins_)
NameError: name '_builtins_' is not defined
>>> def f
SyntaxError: invalid syntax
>>> deff(x)
Traceback (most recent call last):
  File "<pyshell#83>", line 1, in <module>
    deff(x)
NameError: name 'deff' is not defined
>>> def(x)

>>> 
>>> 
>>> 
>>> area(7,2)
Traceback (most recent call last):
  File "<pyshell#4>", line 1, in <module>
    area(7,2)
NameError: name 'area' is not defined
>>> area(7, 2)
Traceback (most recent call last):
  File "<pyshell#5>", line 1, in <module>
    area(7, 2)
NameError: name 'area' is not defined
>>> ================================ RESTART ================================
>>> def area(base, height):
	return base*height/2

>>> area (7,8)
28.0
>>> area (45,122)
2745.0
>>> area (2,123)
123.0
>>> "earthworm"+" poop"
'earthworm poop'
>>> 'Bwa'+'ha'*5
'Bwahahahahaha'
>>> 
>>> 'Mwa' +'ha'*5
'Mwahahahahaha'
>>> 
>>> 'Bwahahahahaha''Mwahahahahaha'
'BwahahahahahaMwahahahahaha'
>>> print("hello")
hello
>>> print(3+7-3)
7
>>> print("Minecraft" "is" "AWESOME!!!!!")
MinecraftisAWESOME!!!!!
>>> def square(num):
	return num**2

>>> def square_P(num):
	print("The square of num is", num**2)

	
>>> anwer_return=square(4)
>>> anwer_return
16
>>> answer_print+ square_P(4)
Traceback (most recent call last):
  File "<pyshell#32>", line 1, in <module>
    answer_print+ square_P(4)
NameError: name 'answer_print' is not defined
>>> square_P(4)
The square of num is 16
>>> answer_print=square_P(4)
The square of num is 16
>>> answer_print
>>> answer_return * 5
Traceback (most recent call last):
  File "<pyshell#36>", line 1, in <module>
    answer_return * 5
NameError: name 'answer_return' is not defined
>>> anwer_return * 5
80
>>> inout('What is your name?')
Traceback (most recent call last):
  File "<pyshell#38>", line 1, in <module>
    inout('What is your name?')
NameError: name 'inout' is not defined
>>> inout('What is your name?')
Traceback (most recent call last):
  File "<pyshell#39>", line 1, in <module>
    inout('What is your name?')
NameError: name 'inout' is not defined
>>> input('What is your name?')
What is your name? Michael 
' Michael '
>>> input('PHHPLT!')
PHHPLT! You farted
' You farted'
>>> '''How
are
you'''
'How\nare\nyou'
>>> (3/t4/t5)
Traceback (most recent call last):
  File "<pyshell#46>", line 1, in <module>
    (3/t4/t5)

>>> (3\t4\t5)
>>> (3\t4\t5)
>>> 3\t4\t5
>>> area(5,8)
>>>10*10
        
