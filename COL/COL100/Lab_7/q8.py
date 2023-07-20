def sort_colors(A):
    i = 0
    j = 0
    while i < len(A):
        if A[i] == 'o':
            A[j], A[i] = A[i], A[j]
            j += 1
        i += 1
    j = len(A) - 1
    i = len(A) - 1

    while i >= 0:
        if A[i] == 'g':
            A[j], A[i] = A[i], A[j]
            j -= 1
        i -= 1
    return A
