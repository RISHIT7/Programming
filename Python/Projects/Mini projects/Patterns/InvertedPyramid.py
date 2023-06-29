n = int(input("Enter the number here: "))

for i in range(n):
    for j in range(n-i):
        print("*", end=" ")
    print()