def rootFinding():
    a = int(input())
    b = int(input())
    c = int(input())
    d = int(input())
    e = int(input())
    error = float(input())
    x = float(input())

    while error < (a*x**4) + (b*x**3) + (c*x**2) + (d*x) + e or (a*x**4) + (b*x**3) + (c*x**2) + (d*x) + e < -1*error:
        x = x - ((a*x**4) + (b*x**3) + (c*x**2) + (d*x) + e)/((4*a*x**3) + (3*b*x**2) + (2*c*x) + (d))
    print(x)
rootFinding()