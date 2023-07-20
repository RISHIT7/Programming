def maxAmt(hval,n):

    if (n < 0):
        return 0
 
    if (n == 0):
        return hval[0]
     
    pick = hval[n] + maxAmt(hval, n - 2)
    notPick = maxAmt(hval, n - 1)
 
    return max(pick, notPick)

print(maxAmt([6, 7, 1, 3, 8, 2, 4], 6))