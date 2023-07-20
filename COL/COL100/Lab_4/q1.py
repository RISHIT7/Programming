def palindrome_checker(s):
	if len(s) == 1 or len(s) == 0:
		return True
	if s[0] == s[-1]:
		return palindrome_checker(s[1:-1])
	else:
		return False