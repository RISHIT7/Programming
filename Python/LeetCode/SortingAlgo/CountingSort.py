arr = [1, 0, 2, 1, 0, 1, 1, 5, 6, 7, 5, 4, 2, 2, 0, 0, 1]
ans = [0]*(len(arr))

k = None
l = None

for el in arr:
    if k == None or k < el:
        k = el
    if l == None or l > el:
        l = el

count = [0]*(k+1)

for el in arr:
    count[el] += 1

for i in range(1, len(count)):
    count[i] += count[i-1]

for i in range(len(arr)):
    ans[count[arr[i]]-1] = arr[i]
    count[arr[i]] -= 1