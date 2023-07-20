def get_index(L, x):
    return BinarySearch(L, 0, len(L)-1, x)

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

def first(L, index):
    while (L[index-1] == L[index]):
        index -= 1
    return index

def last(L, index):
    while (L[index+1] == L[index]):
        index += 1
    return index

def first_and_last(L, x):
    index_0 = get_index(L, x)
    r = first(L, index_0)
    l = last(L, index_0)

    return (r, l)

print(first_and_last([1, 4, 4, 4, 5, 7, 9, 9, 10, 11], 4))