n = int(input("Enter the number of test cases: "))
for i in range(n):
    m = int(input("Enter the number of elements: "))
    arr = []
    for m in range(m):
        arr.append(input())
    count = []
    for element in arr:
        i = 0
        for ele in arr:
            if element == ele:
                i += 1
        count.append(i)
    print(m-max(count)+1)