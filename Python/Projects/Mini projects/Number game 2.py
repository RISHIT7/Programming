import random
i = 0
perm = input("Do you want to play(Y/N): ")

if perm.lower() == 'y':
    print("Lessgo")

elif perm.lower() == 'n':
    print("you have no choice")

ul = int(input("Enter upper limit: "))
ll = int(input("Enter lower-limit: "))
a = random.randint(ll, ul)
while i < 6:
    n = int(input("GUESS: "))
    if n == a:
        print("You guessed it!!")
        break
    elif n < a:
        print("Upre socho")
        i += 1
    elif n > a:
        print(" Niche socho")
if perm.lower() == 'y':
    i = i

elif perm.lower() == 'n':
    i += 1
print("The lower the better, Score " + str(i + 1))
quit()