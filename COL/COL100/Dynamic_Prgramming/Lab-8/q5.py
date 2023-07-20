def isomorphic(x, y):
	print(x, y)
	dictionary = {}
	if len(x) != len(y):
		return False
	for i in range(len(x)):
		if x[i] not in dictionary.keys():	
			dictionary[x[i]] = y[i]
		elif dictionary[x[i]] != y[i]:
			return False
	for keys, values in dictionary.items():
		for key, value in dictionary.items():
			if value == values and key != keys:
				return False
	return True
