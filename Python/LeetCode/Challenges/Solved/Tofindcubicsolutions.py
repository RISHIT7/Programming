# To find the solution of a cubic equation by iteration

print("for the equation ax^3+bx^2+cx+d to be solved")
a = float(input("enter a: "))
b = float(input("enter b: "))
c = float(input("enter c: "))
d = float(input("enter d: "))
iteration = int(input("enter the number of iterations: "))
x = float(input("enter the starting point: "))

for i in range(1, iteration+1):
    x = -((b*x**2+c*x+d)/a)**(1/3)
    print(x)