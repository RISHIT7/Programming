s = input()
palindrome = True

for i in range(len(s)):
    if s[i] != s[len(s)-i-1]:
        palindrome = False

if palindrome == True:
    print("palindrome")
else:
    print("not a palindrome")