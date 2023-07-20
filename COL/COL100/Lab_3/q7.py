def StrToInt(n, ans = 0):
    if len(n) == 1:
        return n
    else:
        ans += int(n)
        n = n[1::]
        StrToInt(n, ans)
    return ans
s = input()
k = s[0]

if k == "-":
    sign = -1
else:
    sign = 1

s = s[1::]
print(sign*StrToInt(s))