name = input("Enter your username here: ")
if len(name) == 0:
    print("Bhai kuch toh likh")
elif len(name) > 10:
    name = name.replace(" ", "")
    if len(name) > 10:
        print("Too long, try a shorter username")
    else:
        print("Your username is: " + name.lower)

else :
    print("Your username is: " + name.lower)