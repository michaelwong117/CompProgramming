def run_me():

    Total = 15
    Max = 5
    prompt = "Enter the number of stones: "
    ###valid_input = range(1, 6)
    pile = Total
    valid = False
    while pile > 0:
            s = input("Player 1: " + "there are " + str(pile) + " stones left. " + prompt)
            pile = pile - int(s)
            if pile <= 0:
                print("Player 1 wins!")
                return
             
            s = input("Player 2: " + "there are " + str(pile) + " stones left. " + prompt)
            pile = pile - int(s)
            if pile <= 0:
                print("Player 2 wins!")
                return
 
     

     
    
    
         
         
