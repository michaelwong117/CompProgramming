#from __future__ import print_function
import sys
import re
data = sys.stdin.readlines()
a = {}
for line in data:
    line = re.sub('[^a-zA-Z0-9-_*. ]', '', line)
    if line in a:
        a[line] += 1
    else:
        a[line] = 1


#print 'a =', a

# Sort dictionary by the keys
keys = a.keys()
keys.sort(key=lambda s: s.lower())
#print 'sorted keys =', keys


# Output phase
for item in keys:
    if "sock" in item:
        # handle socks.
        # compute quotient and remainder.
        # q is the number of true pairs.
        q,r=divmod(a[item], 2)
        if q >= 1:
            print str(q) + "|" + str(item)
        
        if r == 1:
            print '0' + "|" + str(item)

    else:
        # working for shirts and pants.
        print str(a[item]) + "|" + str(item)
        
        
