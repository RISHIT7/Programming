tc = int(input())
for _ in range(tc):
    n = int(input())
    if n <= 3:
        print("-1")
    elif n == 4:
        print("3 1 4 2")
    else:
        arr = [0]*n
        if n%2==0:
            for i in range(1, n//2 + 1):
                arr[2*i - 2] += i
            for i in range(n//2 +1, n+1):
                j = i - n//2
                arr[2*j - 1] += i
        else:
            for i in range(1, n//2+2):
                arr[2*i - 2] += i
            for i in range(n//2 + 2, n+1):
                j = i - n//2 - 1
                arr[2*j - 1] += i
        for ele in arr:
            print(ele, end=" ")
        print()