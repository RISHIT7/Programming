n = int(input())
list_aplhabet = [['A'], 
		        ['B', 'C'], 
		        ['D', 'E', 'F'], 
		        ['G', 'H', 'I', 'J'], 
		        ['K', 'L', 'M', 'N', 'O'], 
		        ['P', 'Q', 'R', 'S', 'T', 'U'], 
		        ['V', 'W', 'X', 'Y', 'Z']]

x = ((-1 + (1+(8*n))**(0.5))/2)
if (x*10)%10 != 0:
	x = int(x) + 1

for i in range(1, x+1):
	for j in range(1, i+1):
		print(list_aplhabet[i-1][j-1], end = " ")
		if (i+j+2 == n) or (i==7 and j == 5):
			break
	print()