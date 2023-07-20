x = float(input())
y = float(input())

dist = ((x**2)+(y**2))**(1/2)

if dist < 1:
	print("inside")
elif dist == 1:
	print("on")
else:
	print("outside")
