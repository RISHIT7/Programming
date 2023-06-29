from copy import copy


def L(x):
    y = x.pop(0)
    x.append(y)
    x = "".join(x)
    return x

def R(x):
    u = x.pop(-1)
    x.insert(0, u)
    x = "".join(x)
    return x

for _ in range(int(input())):
    s = input()
    S = list(s)
    C = copy(S)
    A = L(S)
    B = R(C)
    print(A, B)
    if A == B:
        print("YES")
    else:
        print("NO")