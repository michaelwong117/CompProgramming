spaces_1 = 0
spaces_2 = 0
import random
Player_1 = input("Please enter Player 1's name: ")
Player_2 = input("Please enter Player 2's name: ")

print("The rules of Flash are simple. There are three dice and two players, and you can choose how many you want to roll. First one to the end wins, but watch out! Don't roll a multiple of six, unless you want to move back twenty spaces!")

while spaces_1 < 100 and spaces_2 < 100:
    Num_of_Dice = int(input("Please enter the amount of dice you want to roll " + str(Player_1) + ": "))

    if Num_of_Dice <= 3 and Num_of_Dice > 0:
        print("Rolling", Num_of_Dice, "Dice!")

    elif Num_of_Dice > 3 or Num_of_Dice <= 0:
        print("Sorry, that's not a valid number!")

        Num_of_Dice = input("Please enter the amount of dice you want to roll " + str(Player_1) + ": ")

        print("Rolling", Num_of_Dice, "Dice!")

        x = random.randrange(1, 7)

        print(Player_1, "rolled a", x)

        spaces_1 = spaces_1 + x

    Num_of_Dice = int(input("Please enter the amount of dice you want to roll " + str(Player_2) + ": "))

    if Num_of_Dice <= 3 and Num_of_Dice > 0:
        print("Rolling", Num_of_Dice, "Dice!")

    elif Num_of_Dice > 3 or Num_of_Dice <= 0:
        print("Sorry, that's not a valid number!")

        Num_of_Dice = input("Please enter the amount of dice you want to roll " + str(Player_2) + ": ")

        print("Rolling", Num_of_Dice, "Dice!")

        x = random.randrange(1, 7)

        print(Player_2, "rolled a", x)

        spaces_2 = spaces_2 + x

    if Num_of_Dice == 1:
        x = random.randrange(1, 7)

        print(Player_1, "rolled a", x)

        spaces_1 = spaces_1 + x

        if x % 4 == 0:
            print("Oh No!", Player_1, "rolled a multiple of four! Go back twenty spaces!")
            if spaces_1 <=20:
                spaces_1 = 0
            if spaces_1 > 20:
                spaces_1 = spaces_1 - 20

        x = random.randrange(1, 7)

        print(Player_2, "rolled a", x)

        spaces_2 = spaces_2 + x

        if x % 4 == 0:
            print("Oh No!", Player_2, "rolled a multiple of four! Go back twenty spaces!")
            if spaces_2 <=20:
                spaces_2 = 0
            if spaces_2 > 20:
                spaces_2 = spaces_2 - 20

    if Num_of_Dice == 2:
        x = random.randrange(2, 13)

        print(Player_1, "rolled a", x)

        spaces_1 = spaces_1 + x

        if x % 4 == 0:

            print("Oh No!", Player_1, "rolled a multiple of four! Go back twenty spaces!")
            if spaces_1 <=20:
                spaces_1 = 0
            if spaces_1 > 20:
                spaces_1 = spaces_1 - 20
            x = random.randrange(2, 13)

        print(Player_2, "rolled a", x)

        spaces_2 = spaces_2 + x

        if x % 4 == 0:

            print("Oh No!", Player_2, "rolled a multiple of four! Go back twenty spaces!")
            if spaces_2 <=20:
                spaces_2 = 0
            if spaces_2 > 20:
                spaces_2 = spaces_2 - 20
    if Num_of_Dice == 3:
        x = random.randrange(3, 19)

        print(Player_1, "rolled a", x)

        spaces_1 = spaces_1 + x

        if x % 4 == 0:
            print("Oh No!", Player_1, "rolled a multiple of four! Go back twenty spaces!")
            if spaces_1 <=20:
                spaces_1 = 0
            if spaces_1 > 20:
                spaces_1 = spaces_1 - 20
        x = random.randrange(3, 19)

        print(Player_2, "rolled a", x)

        spaces_2 = spaces_2 + x

        if x % 4 == 0:
            print("Oh No!", Player_2, "rolled a multiple of four! Go back twenty spaces!")
            if spaces_2 <=20:
                spaces_2 = 0
            if spaces_2 > 20:
                spaces_2 = spaces_2 - 20
    if spaces_1 > 90 and spaces_1 < 100:
        print("Almost there", Player_1, "! Keep on going!")
    if spaces_2 > 90 and spaces_2 < 100:
        print("Almost there", Player_2, "! Keep on going!")
    if spaces_1 > 100:
        print("Congratulations", Player_1, "! You win!")
    if spaces_2 > 100:
        print("Congratulations", Player_2, "! You win!")
