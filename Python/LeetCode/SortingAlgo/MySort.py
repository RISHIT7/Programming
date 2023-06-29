mylist = []
sorting = []
i = int(input("Number of elements: "))
while len(mylist) < i:
    mylist.append(int(input("Enter the element: ")))

print(sorted(mylist))

while len(sorting) != i:
    sorting.append(min(mylist))
    mylist.remove(min(mylist))

print(sorting)

# method 2, more legit
sorted=[]
i = 0
while i < len(mylist):
    minVal = 999999999999999999999999999
    for element in mylist:
        if minVal > element:
            minVal = element
    print(minVal)
    sorted.append(minVal)
    mylist.remove(minVal)

print(sorted)