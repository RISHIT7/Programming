from math import floor
def returnBit(S, n):
    i = 1
    X = 0
    for _ in range(n):
        print(i, S%10)
        X += (S%10)*i
        S -= S%10
        S /= 10
        i *= 2
    return X
for _ in range(int(input())):
    n = int(input())
    s1 = int(input())
    X1 = returnBit(s1, n)
    a = (10**n - 1)/9
    s2 = a-s1
    X2 = returnBit(s2, n)
    Y = 1
    while floor(X1/(2**Y)) != X2:
        Y += 1
    print(Y)