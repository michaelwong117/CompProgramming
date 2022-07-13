def N_and_A():
    NAMES = ["Alice", "Bob", "Cathy", "Dan", "Ed", "Frank", "Gary", "Helen",
             "Irene", "Jack", "Kelly", "Larry"]
    AGES = [20, 21, 18, 18, 19, 20, 20, 19, 19, 19, 22, 19]
    D = {}
    x = 0
    for n in NAMES:
        D[n] = AGES[x]
        x += 1
    return D


def ages(i):
    l = []
    # Construct the dictionary.
    D = N_and_A()

    # Sample code to iterate over the dictionary.
    #for name, age in D.items():
        #print(name, age)
        
    for name, age in D.items():
        if age == i:
            l.append(name)
    
        
    print(l)
    return



       
        
print(ages(18)) == ["Cathy", "Dan"]
print(ages(19)) == ["Ed", "Helen", "Irene", "Jack", "Larry"]
print(ages(20)) == ["Alice", "Frank", "Gary"]
print(ages(21)) == ["Bob"]
print(ages(22)) == ["Kelly"]
print(ages(23)) == []

