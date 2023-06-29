from itertools import count
for _ in range(int(input())):
    n = int(input())
    arr = [int(v) for v in input().split()]
    Count = []
    for i in range(n):
        Count.append(arr.count(arr[i]))
    print(n-max(Count))