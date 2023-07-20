x = float(input())
error = float(input())
ans = 1
last = 1
i = 0
while (last/x**(i))*(1/((i+1)*(i+2))) > error:
	last *= ((x**2)/((i+1)*(i+2)))
	ans = ans + ((-1)**((i+2)/2))*(last)
	i += 2
last *= ((x**2)/((i+1)*(i+2)))
ans = ans + ((-1)**((i+2)/2))*(last)
print(ans)