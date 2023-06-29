from math import comb

for _ in range(int(input())):
    N, M = [int(v) for v in input().split()]
    count = 0
    for n in range(1, N+1):
        for m in range(n+1):
            if (n-m) % 3 == 0 and m <= M:
                count += comb(N, n)*comb(M, m)
    print(int(count))