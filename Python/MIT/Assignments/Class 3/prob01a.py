
import math

# get the values of a, b, and c using input.

a = float(input("a = "))

b = float(input("b = "))

c = float(input("c = "))


first_root = (-b + math.sqrt(b*b - 4*a*c))/2*a
second_root = (-b - math.sqrt(b*b - 4*a*c))/2*a


print("The 1st root is", first_root)


print("The 2nd root is", second_root)

