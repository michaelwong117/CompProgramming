def my_quiz():
    import time
    Q1 = input("Question 1: What is my favorite color?: ")
    total = 0
    if Q1 == "Black" or Q1 == "black":
        print("Correct! Onto the next question!")
        total = total + 1
    else:
        print("Incorrect! Onto the next question!")

    Q2 = input("Question 2: Who is my best friend?: ")
    if Q2 == "Reilly" or Q2 == "reilly":
        print("Correct! Onto the next question!")
        total = total + 1
    else:
        print("Incorrect! Onto the next question!")

    Q3 = input("Question 3: What is my middle name?: ")
    if Q3 == "James" or Q3 == "james":
        print("Correct! Onto the next question!")
        total = total + 1
    else:
        print("Incorrect! Onto the next question!")

    Q4 = input("Question 4: What period do I have lunch?: ")
    if Q4 == "4" or Q4 == "Four":
        print("Correct! Onto the next question!")
        total = total + 1
    else:
        print("Incorrect! Onto the next question!")

    Q5 = input("Question 5: What am I doing right now?: ")
    if Q5 == "Programming" or Q5 == "programming":
        print("Congratz! You're either a stalker, or you're sitting next to me. Calculating your results!")
        total = total + 1
    else:
        print("Incorrect! Calculating your results!")
    time.sleep(3)
    if total == 5:
        print("So... did you plant a camera in my room or what?")
    if total == 4:
        print("Good job! Four out of five!")
    if total == 3:
        print("Three out of five! Nice!")
    if total == 2:
        print("Well, at least you got two right!")
    if total == 1:
        print("Hello, and nice to meet you! I would congratulate you, but you only got one correct...")
    if total == 0:
        print("I would commend you on your effort, but my parents said not to talk to strangers.")

    
        
    
