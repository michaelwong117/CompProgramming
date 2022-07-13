from random import *

import sys
sys.stdout = open('cowpatibility.in','wt')
n = int(1e5)
print(n)
for x in range(0, n):
    print(" ".join([str(randrange(1e6)) for _ in range(0, 5)]))
