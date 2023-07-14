def distinctPrimeFactors(N):

    if (N < 2):
        print(-1)
        return
    if N == 2:
        print(2)
        return
    visited = {}
    res = []
    i = 2
    while (i * i <= N):
        while (N % i == 0):
            if (i not in visited):
                res.append(i)
                visited[i] = 1

            N //= i
        i += 1

    if (N > 2):
        res.append(N)
    return res


for _ in range(int(input())):
    arr = distinctPrimeFactors(int(input()))
    res = 1
    for el in arr:
        res *= el
    print(res)