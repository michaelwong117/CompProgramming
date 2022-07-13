from random import randint
spaces = ["Error",0,0]
def roll_dice(n) :
    if n==1:
        num=randint(1,7)
    if n==2:
        num=randint(2,13)
    if n==3:
        num=randint(3,19)
    return num
def move_spaces(s,p) :
    if s%6==0:
        print("Oh No! "+p+" rolled a multiple of six! Go back twenty spaces!")
        if p==p_1:
            if spaces[1] < 20:
                spaces[1]=0
            else:
                spaces[1]-=20
        if p==p_2:
            if spaces[2] < 20:
                spaces[2]=0
            else:
                spaces[2]-=20
    if s%9==0:
        print("Flash!")
        if p==p_1:
            spaces[1]+=20
        if p==p_2:
            spaces[2]+=20
    else:
        if p==p_1:
            spaces[1]+=s
        if p==p_2:
            spaces[2]+=s
print("The rules of Flash are simple. There are three dice and two players, and you can choose how many you want to roll. Roll a multiple of nine, and flash your way to the finish! First one to the end wins, but watch out! Don't roll a multiple of six, unless you want to move back twenty spaces!")
p_1 = input("Please enter Player 1's name: ")
p_2 = input("Please enter Player 2's name: ")
while spaces[1]<100 and spaces[2]<100:
    x=True
    while x:
        d_1 = int(input("Please enter the amount of dice you want to roll, " + str(p_1) + ": "))
        if d_1 <= 3 and d_1 > 0:
            print("Rolling", d_1, "Dice!")
            n_1=roll_dice(d_1)
            x=False
    
        elif d_1 > 3 or d_1 <= 0:
            print("Sorry, that's not a valid number! Remember, you have only three dice!")
    x=True
    while x:
        d_2 = int(input("Please enter the amount of dice you want to roll, " + str(p_2) + ": "))
        if d_2 <= 3 and d_2 > 0:
            print("Rolling", d_2, "Dice!")
            n_2=roll_dice(d_2)
            x=False
    
        elif d_2 > 3 or d_2 <= 0:
            print("Sorry, that's not a valid number! Remember, you have only three dice!")
    move_spaces(n_1,p_1)
    move_spaces(n_2,p_2)
    print (p_1+" is at space number "+str(spaces[1]))
    print (p_2+" is at space number "+str(spaces[2]))
    if spaces[1] > 90 and spaces[1] < 100:
        print("Almost there "+p_1+"! Keep on going!")
    if spaces[2] > 90 and spaces[2] < 100:
        print("Almost there "+p_2+"! Keep on going!")
    if spaces[1] >= 100:
        print("Congratulations "+p_1+"! You win!")
    if spaces[2] >= 100:
        print("Congratulations "+p_2+"! You win!")
print("Program over")
