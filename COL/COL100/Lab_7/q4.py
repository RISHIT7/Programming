def get_intersection1(A, B, m=0, n=0, ans=[]):
    if m+1 == len(A) and n+1 == len(B):
        return ans
    elif m+1 == len(A) and n+1 < len(B):
        if A[m] == B[n]:
            ans.append(A[m])
        return get_intersection1(A, B, m, n+1, ans)
    elif m+1 < len(A) and n+1 == len(B):
        if A[m] == B[n]:
            ans.append(A[m])
        return get_intersection1(A, B, m+1, n, ans)
    elif m+1 < len(A) and n+1 < len(B):
        if A[m] == B[n]:
            ans.append(A[m])
            return get_intersection1(A, B, m+1, n+1, ans)
        elif A[m] > B[n]:
            return get_intersection1(A, B, m, n+1, ans)
        else:
            return get_intersection1(A, B, m+1, n, ans)

def get_intersection(A, B, C):
    D = get_intersection1(A, B)
    E = get_intersection1(D, C, 0, 0, [])
    return E
