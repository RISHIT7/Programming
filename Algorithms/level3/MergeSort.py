def mergeSort(arr):
    if len(arr) > 1:
        # Finding thr mid of array
        mid = len(arr)//2
        # Diving the array elements
        L = arr[:mid]
        R = arr[mid:]
        # Sorting the first half
        mergeSort(L)
        # Sorting the second half
        mergeSort(R)
        i = j = k = 0
        #Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else :
                arr[k] = R[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

# code to print the list

def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()

# Driver code
if __name__ == "__main__":
    arr = [45, 44, 65, 67, 87, 90, 1, 2, 3, 467, 5, 89, 0]
    print("Given array is", end="\n")
    printList(arr)
    mergeSort(arr)
    print("sorted array is: ", end="\n")
    printList(arr)