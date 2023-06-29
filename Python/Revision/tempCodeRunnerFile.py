    if (i+1 < len(A)) and (A[i] > A[i+1]):
        B[x].append(A[i])
    elif (i+1 < len(A)) and (A[i] < A[i+1]):
        B[x].append(A[i])
        if x == 0:
            x = 1
        elif x == 1:
            x = 0