### Solution 1 ###
for _ in range(int(input())):
    n = int(input())
    arr = [0]*n
    for i in range(n):
        k = input()
        arr[i] = list(k)
    for i in range(len(arr)):
        if i-1 >= 0:
            for j in range(len(arr[i-1])):
                if arr[i][j] == arr[i-1][j]:
                    arr[i][j] = '0'
                else:
                    arr[i][j] = '1'
    result = 0
    for ele in arr[2]:
        if ele == '1':
            result += 1
    print(result)

### Solution 2 ###
def XOR(arr):
    if len(arr) > 1:
        for j in range(len(arr[0])):
            if arr[1][j] == arr[0][j]:
                arr[1][j] = '0'
            else:
                arr[1][j] = '1'
        arr.remove(arr[0])
        XOR(arr)
    else:
        result = 0
        for ele in arr[0]:
            if ele == '1':
                result += 1
        print(result)

for _ in range(int(input())):
    n = int(input())
    arr = [0]*n
    for i in range(n):
        k = input()
        arr[i] = list(k)
    A = XOR(arr)