
import hashlib

def encrypt(password):
    return hashlib.md5(password.encode('utf-8')).digest()


def run_me():
    hashed_value = b'\x90\x01P\x98<\xd2O\xb0\xd6\x96?}(\xe1\x7fr'
    prompt = 'Enter the password: '
    password_correct = False
    counter = 3
    while not password_correct:
        answer = input(prompt)
        if encrypt(answer) == hashed_value:
            password_correct = True
        if password_correct == False:
            counter = counter - 1
        if counter == 0:
            print("GAME OVER")
            return
    print("Access granted")
    return


            
        
    
    
    
 


    
  
