
import hashlib

def encrypt(password):
    return hashlib.md5(password.encode('utf-8')).digest()


def run_me():
    hashed_value = b'\x90\x01P\x98<\xd2O\xb0\xd6\x96?}(\xe1\x7fr'
    prompt = 'Enter the password: '
    password_correct = False
    counter = 3
    while not password_correct and counter > 0:
        answer = input(prompt)
        if encrypt(answer) == hashed_value:
            password_correct = True
        else:
            counter -= 1
  
            
    if password_correct == True:
        print("Access granted")
    else:
        print("GAME OVER")
    return



            
        
    
    
    
 


    
  
