# not an effeicient method as well
def bubbleSort(mylist):
    for i in range(0, len(mylist)-1):
        for j in range(0, len(mylist) - 1 - i):
            if mylist[j] > mylist[j+1]:
                mylist[j], mylist[j+1] = mylist[j+1], mylist[j]

    return mylist

# [6, 3, 5, 2, 8, 1, 6, 2, 9, 1]
# [3, 5, 2, 6, 1, 6, 2, 8, 1, 9]
# [3, 2, 5, 1, 6, 2, 6, 1, 8, 9]
# [2, 3, 1, 5, 2, 6, 1, 6, 8, 9]
# [2, 1, 3, 2, 5, 1, 6, 6, 8, 9]
# [1, 2, 2, 3, 1, 5, 6, 6, 8, 9]
# [1, 2, 2, 1, 3, 5, 6, 6, 8, 9]
# [1, 2, 1, 2, 3, 5, 6, 6, 8, 9]
# [1, 1, 2, 2, 3, 5, 6, 6, 8, 9]
# [1, 1, 2, 2, 3, 5, 6, 6, 8, 9]
# [1, 1, 2, 2, 3, 5, 6, 6, 8, 9]