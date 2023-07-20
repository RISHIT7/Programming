def maxAmt(hval,n=0):
    if (n > len(hval)-1):
        return 0
 
    if (n == len(hval)-1):
        return hval[len(hval)-1]

    pick = hval[n] + maxAmt(hval, n + 2)
    notPick = maxAmt(hval, n + 1)
    return max(pick, notPick)

def max_value(V):
    val = maxAmt(V)
    return val

print(max_value([6, 7, 1, 3, 8, 2, 4]))