n = int(input())
arr = []

def Armstrong(n, arr, k=n):
    while n > 0:
        arr.append(n % 10)
        n //= 10

    sum = 0

    for i in range(len(arr)):
        sum += arr[i]**(len(arr))

    if sum == k:
        print("Armstrong")
    else:
        print("Not Armstrong")

Armstrong(n, arr)