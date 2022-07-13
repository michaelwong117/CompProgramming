def shift_left(s):
    left = []
    for i in range(len(s) - 1):
        left.append(s[i + 1])
    left.append(s[0])
    #left = ''.join(left)
    #print(left)
    return left

def scramble(text):
    total = 0
    while total < 10:
        import random
        import string
        x = random.choice(string.hexdigits)
        y = random.choice(string.hexdigits)
        scram = shift_left(text)
        #print(left)
        list.reverse(scram)
        #print(scram)
        scram.append(x)
        #print(scram)
        list.reverse(scram)
        scram.append(y)
        scram = shift_left(scram)
        list.reverse(scram)
        scram.insert(-4, "abcd")
        scram.insert(-8, "jklf")
        scram.insert(0, "!") or scram.insert(-7, ".")
        scram.insert(-4, "arivmsu4yd,f;-")
        total += 1
    scram = ''.join(scram)
    return scram



        
    


    
    
