for _ in range(int(input())):
    n = int(input())
    k = input()
    lst = list(k)
    j = 0
    if lst[0] == '1':
        j += 1
    if lst[n-2] == '0':
        j += 1
    for i in range(1, n-1):
        if lst[i-1] == '0' and lst[i] == '1':
            j += 1
    print(j)