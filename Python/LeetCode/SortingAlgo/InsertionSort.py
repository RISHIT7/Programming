# not good for long lists, many nested loops

## SWAPING ##
def insertion_sortFor(A):
    for i in range(1, len(A)):
        for j in range(i-1, -1, -1):
            if A[j] > A[j+1]:
                A[j], A[j+1] = A[j+1], A[j]
            else:
                break
    return A


def insertion_sortWhile(A):
    for i in range(1, len(A)):
        j = i - 1
        while A[j] > A[j+1] and j >= 0:
            A[j], A[j+1] = A[j+1], A[j]
            j -= 1
    return A
## SHIFTING ##


def insertion_sortS(A):
    for i in range(1, len(A)):
        curNum = A[i]
        for j in range(i-1, -1, -1):
            if A[j] > curNum:
                A[j+1] = A[j]
            else:
                A[j+1] = curNum
                break
    return A


A = [12, 11, 13, 5, 6, 7]
print(insertion_sortS(A))