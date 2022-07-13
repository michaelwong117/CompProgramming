def find_largest_element(s):
    s2 = s[0]
    for i in s:
        if i > s2:
            s2  = i
            
            
    s.remove(s2)
    #print(s)
            
    return s2



def sort_list(l):
    while len(l) != 0:
        m = find_largest_element(l)
        print(m)
        
    
    
    
    



   






    
