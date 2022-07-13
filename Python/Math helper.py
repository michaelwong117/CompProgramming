def sum(n):
    sum = 0
    for i in range(n+1):
        sum = sum + i
    print(sum)

    
def fact(n):
    answer1 = 1
    for i in range(1, n+1):
        answer1 = answer1 * i
    return answer1


def P(x, y):
    a = fact(x) / fact((x - y))
    return(a)
   
    

def P2(x, y):
    b = 1
    for i in range(x - y + 1, x + 1):
        b = b * i  
    return b


def C(x, y):
    c = fact(x) / (fact(x - y) * fact(y))
    return c

    

    
