for _ in range(int(input())):
    n = int(input())
    arr = [int(v) for v in input().split()]
    i = 1
    while i in arr:
        i += 1
    print(i)