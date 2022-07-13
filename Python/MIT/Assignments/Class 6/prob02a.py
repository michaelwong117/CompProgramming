def convert_word_pig_latin(word):
    vowels = ['a','e','i','o','u']
    if word[0] in vowels:
        return(word + 'hay')

    return(word[1:] + word[0] + 'ay')

def convert_txt_pig_latin(txt):
    sentence = ''
    for w in txt.split():
        sentence += (convert_word_pig_latin(w))
        sentence += ' '

    return sentence
        
    
      

    
    
  
        
    
    
  
    

    
    
    
        
        
        
