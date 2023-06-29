# Iterative binary search

def binary_search(arr, start, end, target):
    while start <= end:
        mid = (start+end)//2
        if arr[mid] < target:
            start = mid + 1
        elif arr[mid] > target:
            end = mid - 1
        else :
            return mid
    return start

arr = [2, 5, 8, 10, 11, 22, 25]
target = 8

result = binary_search(arr, 0, len(arr)-1, target)
# Recursive method

def BinarySearch(arr, start, end, target):
    if end >= start:
        mid = (start+end)//2
        if arr[mid] < target:
            x = BinarySearch(arr, mid+1, end, target)
        elif arr[mid] > target:
            x = BinarySearch(arr, start, mid-1, target)
        else :
            return mid
    else :
        return -1
    return x

arr = [2, 5, 8, 10, 11, 22, 25]
target = 8

result = BinarySearch(arr, 0, len(arr)-1, target)
print(result)