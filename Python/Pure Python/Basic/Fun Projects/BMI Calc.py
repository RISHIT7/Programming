G = input("Write M for Men and W for Women: ")
M = input("Enter your weight in kg here: ")
L = input("Enter your height in meters here: ")

R = float(M) / float(L)

if G == "M":
    if R <= 18:
        print("Suklakdi")
    elif R <= 24:
        print("Prafact")
    elif R <= 29:
        print("Paisa vada cho")
    elif R <= 39:
        print("Bau Paisa aavi gaya!?")
    else :
        print("Ochu kha thodu, dushkad padi gayu")

else :
    if R <= 18:
        print("Suklakdi")
    elif R <= 24:
        print("Prafact")
    elif R <= 29:
        print("Paisa vada cho")
    elif R <= 39:
        print("Bau Paisa aavi gaya!?")
    else :
        print("Ochu kha thodu, dushkad padi gayu")
