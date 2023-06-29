n = int(input())
for i in range(n):
    for j in range(i):
        print(" ", end="")
    for j in range(n, i, -1):
        print(j, end="")
    for j in range(i+2, n+1):
        print(j, end="")
    print()