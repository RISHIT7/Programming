def pascal(n):
    if n == 0:
        return []
    elif n == 1:
        return [1]
    else:
        nTh = [1]
        nMinusOneTh = pascal(n-1)
        for i in range(len(nMinusOneTh)-1):
            nTh.append(nMinusOneTh[i] + nMinusOneTh[i+1])
        nTh += [1]
    return nTh