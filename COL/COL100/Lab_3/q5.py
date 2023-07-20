def GCD(a, b):
    if a == b:
        return a
    elif a > b:
        return GCD(a-b, b)
    else:
        return GCD(a, b-a)

def LCM(a, b):
    return int(a*b/GCD(a, b))

a = int(input())
b = int(input())
print(LCM(a, b))