## SOlution 1##
for _ in range(int(input())):
    arr = [int(v) for v in input().split()]
    A = []
    A.append(arr[0])
    arr.pop(0)
    for i, _ in enumerate(arr):
        if A[-1] > arr[0]:
            A.append(arr.pop(0))
        else:
            break
    if (len(A) == 0) or (len(arr) == 0):
        print(-1)
    else:
        print(len(A))
        for e in A:
            print(e, end=" ")
        print()
        print(len(arr))
        for e in arr:
            print(e, end=" ")
        print()

## Solutino 2 ##
for _ in range(int(input())):
    n = int(input())
    A = [int(v) for v in input().split()]
    B = [[], []]
    x = 0
    for i, e in enumerate(A):
        if (i+1 < len(A)) and (A[i] > A[i+1]):
            B[x].append(A[i])
        elif (i+1 < len(A)) and (A[i] < A[i+1]):
            B[x].append(A[i])
            if x == 0:
                x = 1
            elif x == 1:
                x = 0
        else:
            if A[i] > A[i-1]:
                B[1].append(A[i])
            else:
                B[0].append(A[i])
    if (len(B[0]) == 0) or (len(B[1]) == 0):
        print(-1)
    else:
        print(len(B[0]))
        for e in B[0]:
            print(e, end=" ")
        print()
        print(len(B[1]))
        for e in B[1]:
            print(e, end=" ")
        print()