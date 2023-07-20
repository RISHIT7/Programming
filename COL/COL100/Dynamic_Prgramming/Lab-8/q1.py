def uncommon_words(s1, s2):
	s1_list = s1.split()
	s2_list = s2.split()
	for el in s2_list:
		s1_list.append(el)
	dictionary = {}
	for el in s1_list:
		count = 0
		for i in range(len(s1_list)):
			if el == s1_list[i]:
				count += 1
		dictionary[el] = count
	ans = []
	for key, value in dictionary.items():
		if value == 1:
			ans.append(key)
	return ans

