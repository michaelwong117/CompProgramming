# https://www.quora.com/What-are-some-Python-modules-I-should-know-for-competitive-programming
# Prints, N, then N random numbers from 1 to 1e9
from random import *
n = int(1e5)
maxv = int(1e9)
print(n)
print(" ".join([str(randrange(maxv)) for _ in range(n)]))


# Code to find top 3 elements and their counts 
# using most_common 
from collections import Counter 
  
arr = [1, 3, 4, 1, 2, 1, 1, 3, 4, 3, 5, 1, 2, 5, 3, 4, 5] 
counter = Counter(arr) 
top_three = counter.most_common(3) 
print(top_three)



# Python code to find 3 largest and 4 smallest 
# elements of a list. 
import heapq 
  
grades = [110, 25, 38, 49, 20, 95, 33, 87, 80, 90] 
print(heapq.nlargest(3, grades)) 
print(heapq.nsmallest(4, grades)) 


# Python code to demonstrate use of zip. 
import heapq 
  
stocks = { 
    'Goog' : 520.54, 
    'FB' : 76.45, 
    'yhoo' : 39.28, 
    'AMZN' : 306.21, 
    'APPL' : 99.76
    } 
  
zipped_1 = zip(stocks.values(), stocks.keys()) 
  
# sorting according to values 
print(sorted(zipped_1)) 
  
zipped_2 = zip(stocks.keys(), stocks.values()) 
print(sorted(zipped_2)) 
#sorting according to keys 




# Python code to apply a function on a list 
income = [10, 30, 75] 
  
def double_money(dollars): 
    return dollars * 2
  
new_income = list(map(double_money, income)) 
print(new_income) 
