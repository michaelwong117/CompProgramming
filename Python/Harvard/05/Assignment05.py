## Write a Python function which will accept two roman numerals as strings and return their sum,
## also as a roman numeral string (no inputs and prints). For example, if your function is called
## addroman, then addroman("CXXVIII","LXVIII") should return "CLXXXXVI". You may assume that the argument
## values are proper Roman numerals. You do not have to deal with the prefix notation, in which "IIII"
## can be written as "IV", but you shouldn't have more of any one symbol than the value of the next higher
## symbol, that is "IIIII" must be written "V". For those of you who have forgotten, the roman symbols
## have decimal values as in the following table:
##
##M    1000
##D     500
##C     100
##L      50
##X      10
##V       5
##I       1


def convert_numeral(s):
    total = 0
    for n in s:
        if n == "M":
            total += 1000
        if n == "D":
            total += 500
        if n == "C":
            total += 100
        if n =="L":
            total += 50
        if n =="X":
            total += 10
        if n =="V":
            total += 5
        if n =="I":
            total += 1
    return total

print(convert_numeral("MD"))
print(convert_numeral("XVI"))
print(convert_numeral("MDCCCCLXXXV"))


def addroman(s1, s2):
    total_M = 0
    total_D = 0
    total_C = 0
    total_L = 0
    total_X = 0
    total_V = 0
    total_I = 0
    for n1 in s1:
        if n1 == "M":
            total_M += 1
        if n1 == "D":
            total_D += 1
        if n1 == "C":
            total_C += 1
        if n1 =="L":
            total_L += 1
        if n1 =="X":
            total_X += 1
        if n1 =="V":
            total_V += 1
        if n1 =="I":
            total_I += 1

    for n2 in s2:
        if n2 == "M":
            total_M += 1
        if n2 == "D":
            total_D += 1
        if n2 == "C":
            total_C += 1
        if n2 =="L":
            total_L += 1
        if n2 =="X":
            total_X += 1
        if n2 =="V":
            total_V += 1
        if n2 =="I":
            total_I += 1
    if total_I >= 5:
        total_I -= 5
        total_V += 1
    if total_V >= 2:
        total_V -= 2
        total_X += 1
    if total_X >= 5:
        total_X -= 5
        total_L += 1
    if total_L >= 2:
        total_L -= 2
        total_C += 1
    if total_C >= 5:
        total_C -= 5
        total_D += 1
    if total_D >= 2:
        total_D -= 2
        total_M += 1

    sum_roman = "M" * total_M + "D" * total_D + "C" * total_C + "L" * total_L + "X" * total_X + "V" * total_V + "I" * total_I
    return sum_roman

print(addroman("CXXVIII", "LXVIII"))
print(addroman("MDCCCCLXXXV", "XVI"))

# Will's torture test no. 1
# Should get "M".
print(addroman("I", "DCCCCLXXXXVIIII"))

# Will's torture test no. 2
# Should get 1998 = "MDCCCLXXXXVIII".
print(addroman("DCCCCLXXXXVIIII", "DCCCCLXXXXVIIII"))


    
    
