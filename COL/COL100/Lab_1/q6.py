a = float(input())
b = float(input())
c = float(input())

D = (b**2) - (4*a*c)
r1 = (-b + (D**(1/2)))/(2*a)
r2 = (-b - (D**(1/2)))/(2*a)

if a == 0:
	print("Not a valid quadratic equation")
elif D > 0:
	print(str(r2) + " " + str(r1))
elif D == 0:
	print(str(r1))
else:
	print("No real roots")
