for _ in range(int(input())):
    n = int(input())
    s = input()
    X1 = returnBit(s)
    y = 0
    mx = 2**8
    i = 1
    while (i <= len(s)):
        temp = X1/(2**i)
        temp = X1^int(temp)
        if temp < mx:
            mx = temp
            y = i
        i += 1
    print(y)