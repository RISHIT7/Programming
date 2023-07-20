def f(a, b, c, d, x):
    return (a**(x**b)) + (c*((1+(x**d))**(1/d)))

def main():
    a = float(input())
    b = float(input())
    c = float(input())
    d = float(input())

    delta = float(input())

    bd1 = float(input())
    bd2 = float(input())
    
    if bd2 < bd1:
        bd1, bd2 = bd2, bd1
    
    integral = 0

    while bd1 < bd2:
        integral += f(a, b, c, d, bd1)*delta
        bd1 += delta
    return integral

print(main())