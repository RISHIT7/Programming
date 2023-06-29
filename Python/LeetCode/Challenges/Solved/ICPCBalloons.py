for _ in range(int(input())):
    n = int(input())
    arr = [int(v) for v in input().split()]
    A = [1, 2, 3, 4, 5, 6, 7]
    i = 0
    while len(A) != 0:
        if arr[i] in A:
            A.remove(arr[i])
        i += 1
    print(i)