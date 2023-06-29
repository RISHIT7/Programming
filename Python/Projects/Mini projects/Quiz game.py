print("Welcome to my computer quiz!")

playing = input("Do you want to play? ")

score = 0

if playing.lower() != "yes":
    print("Looser")
    quit()
else:
    print("Okay! Let's plaay :) ")

    answer = input("Kya chaiye re tereko? ")
    if answer.lower() == "duniya":
        print("Correct!!")
        score += 1
    else:
        print("Incorrect :(, check capitalisation(all lower), and spelling ")
    answer = input("What is 9 plus 10 ")
    if answer.lower() == "21":
        print("Correct!!")
        score += 1
    else:
        print("Incorrect :(, check capitalisation(all lower), and spelling ")
    answer = input(
        "Every 60 seconds in Africa a minute passes, together we can stop this (Yes/ No): ")
    if answer.lower() == "yes":
        print("Correct!!")
        score += 1
    else:
        print("Incorrect :(, check capitalisation(all lower), and spelling ")
    answer = input("Achanak se kya badal gaya ")
    if answer.lower() == "halat" or answer.lower() == "jazbat" or answer.lower() == "duniya":
        print("Correct!!")
        score += 1
    else:
        print("Incorrect :(, check capitalisation(all lower), and spelling ")


print("You got " + str(score) + " questions correct!")
