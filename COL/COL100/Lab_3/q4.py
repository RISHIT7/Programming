def GCD(a, b):
    if a == b:
        return a
    elif a > b:
        return GCD(a-b, b)
    else:
        return GCD(a, b-a)

a = int(input())
b = int(input())
print(GCD(a, b))