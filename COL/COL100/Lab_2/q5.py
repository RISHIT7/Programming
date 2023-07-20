n = int(input())
ans = [0, 0, 0, 1, 1, 2]

while n > 0:
    print(ans[0],end = " ")
    ans[5] = ans[1] + ans[2] + ans[3] + ans[4]
    ans[0] = ans[1]
    ans[1] = ans[2]
    ans[2] = ans[3]
    ans[3] = ans[4]
    ans[4] = ans[5]
    n -= 1