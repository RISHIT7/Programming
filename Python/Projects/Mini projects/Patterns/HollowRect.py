n = int(input("Enter rows here: "))
m = int(input("Enter columns here: "))

for i in range(n):
    if i == 0 or i == n-1:
        for j in range(m):
            print("*", end="")
        print("")
    else:
        print("*", end="")
        for j in range(m-2):
            print("", end=" ")
        print("*\n", end="")
