for _ in range(int(input())):
    n, s = [int(v) for v in input().split()]
    a = [int(v) for v in input().split()]
    i = 0
    j = 0
    st  = -1
    en = -1
    sum = 0
    while (j<n) and (sum + a[j+1] < s):
        sum += a[j]
        j += 1
    if (sum == s):
        print(i+1)
        break
    while (j<n):
        sum += a[j]
        while (sum<s):
            sum -= a[i]
            i += 1
        if sum == s:
            st = i+1
            en = j+1
            break
        j += 1
    if st == en == -1:
        print('-1')
    else:
        print(f"{st} {en}")