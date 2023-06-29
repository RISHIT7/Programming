# Choosing pivot is key, we'llchoose median of 3 pivot
# Divide and conquer algorithm, worst case O(n^2) best case O(n logn)

def quickSort(A):
    quickSort2(A, 0, len(A)-1)


def quickSort2(A, low, hi):
    if low < hi:
        p = partition(A, low, hi)
        quickSort2(A, low, p-1)
        quickSort2(A, p + 1, hi)


def getPivot(A, low, hi):
    mid = (hi + low) // 2
    pivot = hi
    if A[low] < A[mid]:
        if A[mid] < A[hi]:
            pivot = mid
    elif A[low] < A[hi]:
        pivot = low
    return pivot


def partition(A, low, hi):
    pivotIndex = getPivot(A, low, hi)
    pivotValue = A[pivotIndex]
    A[pivotIndex], A[low] = A[low], A[pivotIndex]
    border = low

    for i in range(low, hi + 1):
        if A[i] < pivotValue:
            border += 1
            A[i], A[border] = A[border], A[i]

    A[low], A[border] = A[border], A[low]

    return border
