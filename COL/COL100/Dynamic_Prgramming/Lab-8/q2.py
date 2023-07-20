def range_sum(L, N):
	primes = []
	for i in range(2, N+1):
		prime = True
		for j in range(2, i):
			if i%j == 0:
				prime = False
				break
		if prime == True:
			primes.append(i)
	sum = 0
	for el in primes:
		add = False
		for interval in L:
			if el >= interval[0] and el <= interval[1]:
				add = True
				break
		if add == True:
			sum += el
	return sum

