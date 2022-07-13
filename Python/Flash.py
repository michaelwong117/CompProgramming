spaces = 0
import random

print("The rules of Flash are simple. There are three dice, and you can choose how many you want to roll. First one to the end wins, but watch out! Don't roll a multiple of six, unless you want to move back twenty spaces!")

while spaces < 100:
    Num_of_Dice = int(input("Please enter the amount of dice you want to roll: "))

    if Num_of_Dice <= 3 and Num_of_Dice > 0:
        print("Rolling", Num_of_Dice, "Dice!")

    if Num_of_Dice > 3 or Num_of_Dice <= 0:
        print("Sorry, that's not a valid number!")

        Num_of_Dice = input("Please enter the amount of dice you want to roll: ")

        print("Rolling", Num_of_Dice, "Dice!")

        x = random.randrange(1, 7)

        print("You rolled a", x)

        spaces = spaces + x

    if Num_of_Dice == 1:
        x = random.randrange(1, 7)

        print("You rolled a", x)

        spaces = spaces + x

        if x % 4 == 0:
            print("Oh No! You rolled a multiple of four! Go back twenty spaces!")
            if spaces <=20:
                spaces = 0
            if spaces > 20:
                spaces = spaces - 20

    if Num_of_Dice == 2:
        x = random.randrange(2, 13)

        print("You rolled a", x)

        spaces = spaces + x

        if x % 4 == 0:

            print("Oh No! You rolled a multiple of four! Go back twenty spaces!")
            if spaces <=20:
                spaces = 0
            if spaces > 20:
                spaces = spaces - 20
    if Num_of_Dice == 3:
        x = random.randrange(3, 19)

        print("You rolled a", x)

        spaces = spaces + x

        if x % 4 == 0:
            print("Oh No! You rolled a multiple of four! Go back twenty spaces!")
            if spaces <=20:
                spaces = 0
            if spaces > 20:
                spaces = spaces - 20
    if spaces > 90:
        print("Almost there! Keep on going!")
print("Congratulations! You won!")
