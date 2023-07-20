x = float(input())
n = int(input())

if x != 0 and n != 0:
	ans = 1
	while (n>0) :
		ans *= x 
		n -= 1
	print(f"{ans}")
elif x != 0 and n == 0:
	print("1")
elif x == 0 and n != 0:
	print("0")
else:
	print("1")