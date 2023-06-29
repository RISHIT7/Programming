def LASa():
    _ = int(input())
    arr = [int(v) for v in input().split()]
    A = []
    for i, _ in enumerate(arr):
        if i+1 < len(arr):
            A.append(-1*(arr[i]-arr[i+1]))
    B = []
    for i, el in enumerate(A):
        k = 0
        for j in range(i+1, len(A)):
            if el == A[j]:
                k += 1
            else:
                break
        B.append(k)
    print(max(B)+2)

for _ in range(int(input())):
    LASa()