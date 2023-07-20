def reverse_string(s):
	if len(s) == 1:
		return s[0]
	else:
		return s[len(s)-1] + reverse_string(s[0:len(s)-1])