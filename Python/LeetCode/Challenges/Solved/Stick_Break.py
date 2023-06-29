for _ in range(int(input())):
    L, K = [int(v) for v in input().split()]
    sum = L
    x = 0
    res = abs(1*(K) - L)
    while sum != 1 and sum != 0:
        res = abs(x*(K) - L)
        if res < sum:
            sum = res
        x += 1
    print(sum)