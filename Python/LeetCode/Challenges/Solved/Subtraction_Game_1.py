# [6, 10, 15]
# [6, 10, 9]
# [6, 4, 9]
# [6, 4, 5]
# [2, 4, 5]
# [2, 4, 3]
# [2, 2, 3]
# [2, 2, 1]
# [1, 1, 1] = 1

def function(A):
    a = A[0]
    i = 0
    for ele in A:
        if a == ele:
            i += 1
    if i != len(A):
        sub = max(A) - min(A)
        A = sorted(A)
        A[-1] = sub
        function(A)
    else:
        print(A[0])

for _ in range(int(input())):
    n = int(input())
    A = [int(v) for v in input().split()]
    function(A)