n = int(input("Enter the index here: "))

for i in range(n):
    for j in range(i+1):
        print("* ", end="")
    for j in range(2*(n-i-1)):
        print("  ", end="")
    for j in range(i+1):
        print("* ", end="")
    print()
for i in range(n-1, -1, -1):
    for j in range(i+1):
        print("* ", end="")
    for j in range(2*(n-i-1)):
        print("  ", end="")
    for j in range(i+1):
        print("* ", end="")
    print()