def FibT(n):
    a = 0
    b = 1
    for _ in range(n):
        c = a+b
        a = b
        b = c
    return a

print(FibT(6))