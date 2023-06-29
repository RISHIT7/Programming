for _ in range(int(input())):
    N, K = [int(v) for v in input().split()]
    A = [int(v) for v in input().split()]
    result = [0]*N
    for e in A:
        result[e-1] += 1
    size = 0
    i = 0
    while i < N:
        if not (A[i] == i+1 or result[i] < K):
            size += 1
        i += 1
    print(size)