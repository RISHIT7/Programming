arr = [32, 3, 4, 5, 3, 2, 1, 1]

# ---------BUBBLE SORT-------------

# for i in range(len(arr)):
#     for j in range(1, len(arr)-i):
#         if arr[j-1] > arr[j]:
#             arr[j-1], arr[j] = arr[j], arr[j-1]

# print(arr)

# ---------SELECTION SORT-----------

# for i in range(len(arr)):
#     min_idx = i
#     for j in range(i+1, len(arr)):
#         if arr[min_idx] > arr[j] :
#             min_idx = j

#         arr[i], arr[min_idx] = arr[min_idx], arr[i]

# print(arr)

# ---------INSERTION SORT-----------

# for i in range(1, len(arr)):
#     temp = arr[i]
#     j = i-1

#     while j >= 0 and temp < arr[j]:
#         arr[j+1] = arr[j]
#         j -= 1

#     arr[j+1] = temp

# print(arr)


# ---------MERGE SORT---------------


# def merge_sort(L):
#     if len(L) > 1:

#         mid = len(L)//2

#         leftlist = L[:mid]
#         rightlist = L[mid:]

#         merge_sort(leftlist)
#         merge_sort(rightlist)


#         i, j, k = 0, 0, 0
#         while i < len(leftlist) and j < len(rightlist):
#             if leftlist[i] <= rightlist[j]:
#                 L[k] = leftlist[i]
#                 k += 1
#                 i += 1
#             else:
#                 L[k] = rightlist[j]
#                 k += 1
#                 j += 1

#         while i < len(leftlist):
#             L[k] = leftlist[i]
#             k += 1
#             i += 1

#         while j < len(rightlist):
#             L[k] = rightlist[j]
#             k += 1
#             j += 1

#         return L

# print(merge_sort(arr))


# ---------MERGE SORT, FROM THE NOTES--------------


# def divide(L):
#     if len(L) < 2:
#         return L[:]
#     else:
#         mid = len(L)//2
#         left = divide(L[:mid])
#         right = divide(L[mid:])
#         return merge(left, right)

# def merge(left, right):

#     result = []
#     i = j = 0
#     while i < len(left) and j < len(right):
#         if left[i] <= right[j]:
#             result.append(left[i])
#             i += 1
#         else:
#             result.append(right[j])
#             j += 1

#     while i < len(left):
#         result.append(left[i])
#         i += 1

#     while j < len(right):
#         result.append(right[j])
#         j += 1

#     return result

# print(divide(arr))


# ----------------QUICK SORT-------------------


# def quickSort(A):
#     quickSort2(A, 0, len(A)-1)


# def quickSort2(A, low, hi):
#     if low < hi:
#         p = partition(A, low, hi)
#         quickSort2(A, low, p-1)
#         quickSort2(A, p + 1, hi)


# def getPivot(A, low, hi):
#     mid = (hi + low) // 2
#     pivot = hi
#     if A[low] < A[mid]:
#         if A[mid] < A[hi]:
#             pivot = mid
#     elif A[low] < A[hi]:
#         pivot = low
#     return pivot


# def partition(A, low, hi):
#     pivotIndex = getPivot(A, low, hi)
#     pivotValue = A[pivotIndex]
#     A[pivotIndex], A[low] = A[low], A[pivotIndex]
#     border = low

#     for i in range(low, hi + 1):
#         if A[i] < pivotValue:
#             border += 1
#             A[i], A[border] = A[border], A[i]

#     A[low], A[border] = A[border], A[low]

#     return border
