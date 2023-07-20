def get_minima(L):
    mid = len(L)//2
    if mid-1 > 0 and L[mid-1] < L[mid]:
        return get_minima(L[:mid])
    elif mid+1 < len(L) and L[mid+1] < L[mid]:
        return get_minima(L[mid:])
    else:
        return L[mid]

