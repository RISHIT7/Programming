def merge_sort(I):
    if len(I) > 1:

        mid = len(I) // 2

        L = I[:mid]
        R = I[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j  < len(R):
            if L[i] < R[j]:
                I[k] = L[i]
                i += 1
            else:
                I[k] = R[j]
                j += 1
            k += 1
        
        while i < len(L):
            I[k] = L[i]
            k += 1
            i += 1
        
        while j < len(R):
            I[k] = R[j]
            k += 1
            j += 1

    return I

def connect(I, i):
    a = min(I[i][0], I[i+1][0])
    b = max(I[i][1], I[i+1][1])
    I[i] = (a, b)
    I.pop(i+1)
    return I

def merge_overlap_intervals(I):
    I = merge_sort(I)

    i = 0 
    while i < len(I)-1:
        if I[i][1] > I[i+1][0]:
            I = connect(I, i)
            i -= 1
        i += 1
    return I

# Input is a list of tuples
I = [(1,3), (2,6), (8,10),(7,18)]
print(merge_overlap_intervals(I))