i = 1
n = int(input("Enter numebr here: "))
while i < n+1:
    for _ in range(n-i):
        print("", end = " ")

    for _ in range(i): # [0, 1, 2]
        print(i, end = " ")

    print()
    
    i += 1