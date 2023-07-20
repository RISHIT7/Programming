# --------- Normal version ----------

def Fib(n):
    if n == 1:
        return 1
    elif n == 0:
        return 0
    else:
        return Fib(n-1) + Fib(n-2)

# ---------- Memoization ------------

def FibM(n, M= [0, 1]):
    if len(M) > n:
        return M[n]
    else:
        k = FibM(n-1, M) + FibM(n-2, M)
        M.append(k)
        return k

print(FibM(6))

# ----------- Tabular ---------------

def FibT(n):
    a = 0
    b = 1
    for _ in range(n):
        c = a+b
        a = b
        b = c
    return a

print(FibT(6))