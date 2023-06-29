arr = [2, 5, 4, 1, 7, 5, 6]

def insertion_sort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j-1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i -= 1
        A[i + 1] = key
    print(A)

insertion_sort(arr)

# [2, 5, 4, 1, 7, 5, 6]
# [2, 5, 1, 4, 5, 6, 7]
# [2, 5, 1, 4, 5, 6, 7]
# [1, 2, 5, 4, 5, 6, 7]
# [1, 2, 4, 5, 5, 6, 7]
# [1, 2, 4, 5, 5, 6, 7]
# [1, 2, 4, 5, 5, 6, 7]