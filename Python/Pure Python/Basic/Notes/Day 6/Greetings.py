perm = input("would you want to add a name(Y/N)?: ")

names = []
while perm.lower() == "y":
    name = input("Enter name here: ")
    perm = input("would you want to add a name(Y/N)?: ")
    names.append(name)

for i in range(len(names)):
    if names[i].find('A') == 0:
        print(names[i] + " saalam saheb")
    elif names[i].find('S') == 0:
        print(names[i] + " saalam saheb")
    elif names[i].find('M') == 0:
        print(names[i] + " saalam saheb")
    elif names[i].find('R') == 0:
        print(names[i] + " Chal be")
    else:
        pass
