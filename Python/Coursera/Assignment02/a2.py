def get_length(dna):
    ''' (str) -> int

    Return the length of the DNA sequence dna.

    >>> get_length('ATCGAT')
    6
    >>> get_length('ATCG')
    4
    '''
    

    return len(dna)
  



def is_longer(dna1, dna2):
    ''' (str, str) -> bool

    Return True if and only if DNA sequence dna1 is longer than DNA sequence
    dna2.

    >>> is_longer('ATCG', 'AT')
    True
    >>> is_longer('ATCG', 'ATCGGA')
    False
    '''
    if get_length(dna1) > get_length(dna2):
        return True

    elif get_length(dna1) < get_length(dna2):
        
        return False
    else:
        return False
        
    
    



def count_nucleotides(dna, nucleotide):
    ''' (str, str) -> int

    Return the number of occurrences of nucleotide in the DNA sequence dna.

    >>> count_nucleotides('ATCGGC', 'G')
    2
    >>> count_nucleotides('ATCTA', 'G')
    0
    '''
    num_nct = 0

    for char in dna:
        if char == nucleotide:
            num_nct = num_nct + 1

    return num_nct
     

     
        


def contains_sequence(dna1, dna2):
    ''' (str, str) -> bool

    Return True if and only if DNA sequence dna2 occurs in the DNA sequence
    dna1.

    >>> contains_sequence('ATCGGC', 'GG')
    True
    >>> contains_sequence('ATCGGC', 'GT')
    False
    
    '''
    if dna2 in dna1:
        return True
    else:
        return False

def is_valid_sequence(dna):
    return_val = True
    for char in dna:
        if char not in 'ATGC':
            return_val = False
    return return_val
        
 
def insert_sequence(dna1, dna2, index):
    return dna1[:index] + dna2 + dna1[index:] 
    
 
        
def get_complement(dna):
    if dna in 'A':
        return 'T'
    elif dna in 'T':
        return 'A'
    elif dna in 'G':
        return 'C'
    elif dna in 'C':
        return 'G'
    else:
        return "Not Valid Sequence"


def get_complementry_sequence(dna):
    complementry_sequence = ''
    for char in dna:
        if char in 'ATGC':
             complementry_sequence += get_complement(char)
    return complementry_sequence
    
    
            
    
 
        
        


    
            
            
            
            
       
    
            
        
    
     
         
            

