for _ in range(int(input())):
    n = int(input())
    arr = [int(v) for v in input().split()]
    
    the_3 = 0
    res = 0
    for i in range(3):
        the_3 += arr[i]
    
    if the_3%3 != 0:
        num = 3-the_3%3
        arr[2] += num
        res += num
        the_3 += num
    
    j = 3
    while j < n:
        the_3 -= arr[j-3]
        the_3 += arr[j]
        if the_3%3 != 0:
            num = 3-the_3%3
            arr[j] += num
            res += num
            the_3 += num
        print(arr)
        j += 1
        
    print(res)