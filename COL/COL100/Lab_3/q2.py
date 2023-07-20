s1 = input()
s2 = input()

def NonCommonChar(s1, s2):
    s = s1 + s2
    k = 0
    for i in range(len(s1)):
        if (s1[i] in s2):
            s = s[0:k] + "" + s[k+1::]
            k -= 1
        k += 1
    for i in range(len(s2)):
        if (s2[i] in s1):
            s = s[0:k] + "" + s[k+1::]
            k -= 1
        k += 1
    print(s)

NonCommonChar(s1, s2)