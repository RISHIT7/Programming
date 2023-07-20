def neg_before_pos(L):
    i = 0
    j = 0
    while i < len(L):
        if L[i] < 0:
            k = L.pop(i)
            L.insert(j, k)
            j += 1
        i += 1
    return L

