def fourth_smallest(L):
	i = 0
	while i < 4:
		min_el = L[0]
		for el in L:
			min_el = min(min_el, el)
		L.remove(min_el)
		i += 1
	return min_el
