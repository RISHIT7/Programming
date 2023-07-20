def harmonic_mean(n):
	if len(n) ==1:
		return n[0]
	else:
		return (len(n))/(1/n[-1]+(len(n)-1)/(harmonic_mean(n[0:-1])))