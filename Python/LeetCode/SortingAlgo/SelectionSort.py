# not a fast sorting algorithm, runs O(n^2)

def selection_sort(A):
    for i in range(0, len(A)-1):
        minIndex = i
        for j in range(1+i, len(A)):
            if A[j] < A[minIndex]:
                minIndex = j

        if minIndex != i:
            A[i], A[minIndex] = A[minIndex], A[i]

    return A

# [6, 3, 5, 2, 8, 1, 6, 2, 9, 1]
# [1, 3, 5, 2, 8, 6, 6, 2, 9, 1]
# [1, 1, 5, 2, 8, 6, 6, 2, 9, 3]
# [1, 1, 2, 5, 8, 6, 6, 2, 9, 3]
# [1, 1, 2, 2, 8, 6, 6, 5, 9, 3]
# [1, 1, 2, 2, 3, 6, 6, 5, 9, 8]
# [1, 1, 2, 2, 3, 5, 6, 6, 9, 8]
# [1, 1, 2, 2, 3, 5, 6, 6, 9, 8]
# [1, 1, 2, 2, 3, 5, 6, 6, 9, 8]
# [1, 1, 2, 2, 3, 5, 6, 6, 8, 9]