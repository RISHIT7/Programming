def subArraySum1(arr, start, end, target):
    if start <= end:
        sum = 0
        for i in range(start, end):
            sum += arr[i]
        if sum > target:
            start += 1
            subArraySum1(arr, start, end, target)
        elif sum < target:
            end += 1
            subArraySum1(arr, start, end, target)
        else:
            print(f"{start+1}, {end}")

def subArraySumloop(arr, n, s):
    sum = 0
    start = 0
    i = 0
    while i <= n:
        if sum > s and start < i:
            sum -= arr[start]
            start += 1
        elif sum < s:
            sum += arr[i]
            i += 1
        else:
            print(start+1, i)
            break
    else:
        print("-1")


target=15
# subArraySum1([10, 4, 5, 5], 0, 0, target)
subArraySumloop([1, 2, 3, 7, 5], 5, 12)