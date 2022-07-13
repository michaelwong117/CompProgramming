def run_me():

    Total = 15
    Max = 5
    prompt = "Enter the number of stones: "
    pile = Total
    valid = range(1, 6)
    while pile > 0:
        valid_input_1 = False
        while not valid_input_1:
            s = input("Player 1: " + "there are " + str(pile) + " stones left. " + prompt)
            if int(s) in valid and int(s) <= pile:
                valid_input_1 = True
        # The input from Player 1 is valid here.
        pile = pile - int(s)
        if pile <= 0:
            print("Player 1 wins!")
            return
        valid_input_2 = False
        while not valid_input_2:
            s = input("Player 2: " + "there are " + str(pile) + " stones left. " + prompt)
            if int(s) in valid and int(s) <= pile:
                valid_input_2 = True
        pile = pile - int(s)
        if pile <= 0:
            print("Player 2 wins!")
            return
 



     
    
    
         
         
