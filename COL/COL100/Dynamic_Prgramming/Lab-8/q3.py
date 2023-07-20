def lcs_dp(s1, s2):
	m = len(s1)
	n = len(s2)
	ans = [[0 for i in range(n+1)] for j in range(m+1)]
	for i in range(m+1):
		for j in range(n+1):
			if i == 0 or j == 0:			
				ans[i][j] = 0
			elif s1[i-1] == s2[j-1]:
				ans[i][j] = ans[i-1][j-1] + 1
			else:
				ans[i][j] = max(ans[i-1][j], ans[i][j-1])


	lcs = ""
 

	i = m
	j = n
	while i > 0 and j > 0:

		if s1[i-1] == s2[j-1]:
			lcs += s1[i-1]
			i -= 1
			j -= 1

		elif ans[i-1][j] > ans[i][j-1]:
			i -= 1
             
		else:
			j -= 1

	lcs = lcs[::-1]
	return (ans[m][n], lcs)

