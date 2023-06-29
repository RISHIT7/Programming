mylist = [2, 1, 4, 3, 5, 7, 2, 6, 22, 9, 5, 3, 9, 0, 3, 7, 2]
print(sorted(mylist))


###My Sort###


# sorted = []
# i = 0
# while i < len(mylist):
#     sorted.append(min(mylist))
#     mylist.remove(min(mylist))

# print(sorted)

# sorted=[]
# i = 0
# while i < len(mylist):
#     minVal = 999999999999999999999999999
#     for element in mylist:
#         if minVal > element:
#             minVal = element
#     print(minVal)
#     sorted.append(minVal)
#     mylist.remove(minVal)

# print(sorted)


###Selection Sort###


# def selection_sort(A):
#     for i in range (0, len(A)-1):
#         minIndex = i
#         for j in range(1+i, len(A)):
#             if A[j] < A[minIndex]:
#                 minIndex = j

#         if minIndex != i:
#             A[i], A[minIndex] = A[minIndex], A[i]

#     return A


###Bubble Sort###


# def bubbleSort(mylist):
#     for i in range(len(mylist)-1):
#         for j in range(len(mylist)-1-i):
#             if mylist[j] > mylist[j+1]:
#                 mylist[j], mylist[j+1] = mylist[j+1], mylist[j]

#     return mylist


###InsertionSort###


# def insertionSort(mylist):
#     for i in len(1, len(mylist)):
#         curNum = mylist[i]
#         for j in range(i-1, 0, -1):
#             if mylist[j] > curNum:
#                 mylist[j+1] = mylist[j]
#             else :
#                 mylist[j+1] = curNum
#                 break
#     return mylist


###Merge Sort###


# def mergeSort(A):
#     mergeSort2(A, 0, len(A)-1)
#     print(A)

# def mergeSort2(A, first, last):
#     if first < last:
#         middle = (first + last) // 2
#         mergeSort2(A, first, middle)
#         mergeSort2(A, middle+1, last)
#         merge(A, first, middle, last)

# def merge(A, first, middle, last):
#     L = A[first:middle]
#     R = A[middle:last+1]
#     L.append(9999999999)
#     R.append(9999999999)
#     i = j = 0
#     for k in range(first, last+1):
#         if L[i] <= R[j]:
#             A[k] = L[i]
#             i += 1
#         else :
#             A[k] = R[j]
#             j += 1
#     return A


###Quick Sort###


# def quickSort(A):
#     quickSort2(A, 0, len(A)-1)


# def quickSort2(A, low, high):
#     if low < high:
#         p = partition(A, low, high)
#         quickSort2(A, low, p-1)
#         quickSort2(A, p+1, high)


# def getPivot(A, low, high):
#     mid = (low + high) // 2
#     pivot = high
#     if A[low] < A[mid]:
#         if A[mid] < A[high]:
#             pivot = mid
#     elif A[low] < A[high]:
#         pivot = low
#     return pivot


# def partition(A, low, high):
#     pivotIndex = getPivot(A, low, high)
#     pivotValue = A[pivotIndex]
#     A[pivotIndex], A[low] = A[low], A[pivotIndex]
#     border = low

#     for i in range(low, high + 1):
#         if A[i] < pivotValue:
#             border += 1
#             A[i], A[border] = A[border], A[low]

#     A[low], A[border] = A[border], A[low]

#     return border


###QuickSelectionSort###


# threshold = 20


# def quickSort(A):
#     quickSort2(A, 0, len(A)-1)


# def quickSort2(A, low, high):
#     if low < high:
#         p = partition(A, low, high)
#         quickSort2(A, low, p-1)
#         quickSort2(A, p+1, high)


# def getPivot(A, low, high):
#     mid = (high + low) // 2
#     pivot = high
#     if A[low] < A[mid]:
#         if A[mid] < A[high]:
#             pivot = mid
#     elif A[low] < A[high]:
#         pivot = low
#     return pivot


# def partition(A, low, high):
#     pivotIndex = getPivot(A, low, high)
#     pivotValue = A[pivotIndex]
#     A[pivotIndex], A[low] = A[low], A[pivotIndex]
#     border = low

#     for i in range(low, high + 1):
#         if A[i] < A[pivotValue]:
#             border += 1
#             A[i], A[border] = A[border], A[i]

#     A[low], A[border] = A[border], A[low]

#     return border
