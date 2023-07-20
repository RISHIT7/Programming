n = int(input())

def perfectNum(n):
    arr = []

    for i in range(n//2):
        if n%(i+1) == 0:
            arr.append(i+1)

    sum = 0
    for el in arr:
        sum += el
        
    if sum == n:
        print("Perfect")
    else:
        print("Not Perfect")

perfectNum(n)