import random
i = 0
perm = input("Do you want to play the game?(Y/N): ")

if perm.lower() == 'y':
    ul = int(input("Set an upper bound: "))
    ll = int(input("Set a lower bound: "))
    a = random.randint(ll, ul)
    while perm.lower() == 'y':
        n = int(input("Enter the guess: "))
        if n > a:
            print("You were above the number")
            i += 1
        elif n < a:
            print("You were below the number")
            i += 1
        else :
            print("You guessed it!")
            print("You got it in " + str(i+1) + " attempts")
            perm = input("Do you want to play the game?(Y/N): ")
            a = random.randint(ll, ul)
else :
    quit()