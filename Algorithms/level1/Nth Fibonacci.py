n = int(input("Enter the value of 'n': "))
a = 0
b = 1
def NthFib(a, b, n):
    i = 0
    print(a)
    print(b)
    while (n-2)//2 > i:
        a = a + b
        b = a + b
        print(a)
        print(b)
        i += 1
    if n%2 != 0:
        print(a + b)
        print(f"The {n}th number is {a+b}")
    else :
        print(f"The {n}th number is {b}")
NthFib(a, b, n)

### Method 2 ###
n = int(input("Enter the number of index here: "))
a = 0
b = 1
print(a)
def getNthFib(n, a, b):
    if n > 1 :
        print(b)
        c = a + b
        n -= 1
        getNthFib(n, b, c)

getNthFib(n, a, b)