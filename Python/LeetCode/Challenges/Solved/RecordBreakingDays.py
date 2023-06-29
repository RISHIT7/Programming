def check(arr, n):
    max = 0
    for i in range(len(arr)):
        if (i+1 == n-1) and (arr[i] < arr[i+1]):
            max += 1
        elif (i+1 < n-1) and (i-1 >= 0) and (arr[i-1] < arr[i] > arr[i+1]):
            max += 1
    return max

def RBDa():
    n = int(input())
    arr = [int(v) for v in input().split()]
    res = check(arr, n)
    print(res)
for _ in range(int(input())):
    RBDa()