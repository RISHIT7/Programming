for _ in range(int(input())):
    n = int(input())
    arr = [int(v) for v in input().split()]
    dict = {}
    minidx = 2^31
    for i, el in enumerate(arr):
        if el not in dict:
            dict[el] = i
        else:
            minidx =  min(minidx, dict[el])
    if minidx != 2^31:
        print(arr[minidx])
    else:
        print("-1")