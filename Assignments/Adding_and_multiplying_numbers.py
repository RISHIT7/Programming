def addingNumbers(a, b):
    i = 0
    c = [0]*(max(len(a), len(b))+1)
    for i in range(min(len(a), len(b))):
        c[i] += a[i] + b[i]

    if len(a) > len(b):
        for i in range(len(a) - len(b)):
            c[i + len(b)] = a[i + len(b)]

    elif len(a) < len(b):
        for i in range(len(b) - len(a)):
            c[i + len(a)] = b[i + len(a)]

    for i in range(len(c)):
        if c[i] >= 10:
            c[i+1] += 1
            c[i] -= 10

    return c

def main():
    a = [int(v) for v in input().split()]
    b = [int(v) for v in input().split()]

    res = (addingNumbers(a, b))
    print(res)
    

if __name__ == "__main__":
    main()