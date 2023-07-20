# ---------- Recursion ------------

def paths(n, m):
    if n == 1 and m == 1:
        return 1
    elif n == 1:
        return paths(n, m-1)
    elif m == 1:
        return paths(n-1, m)
    else:
        return paths(n-1, m) + paths(m-1, n)

# print(paths(2, 3))

# ----------- Memoization ----------

def pathsM(n, m, cache={}):
    key = (n, m)
    if key in cache:
        return cache[key]
    if m == 1 and n == 1:
        return 1
    if m == 0 or n == 0:
        return 0
    cache[key] = pathsM(n, m-1, cache) + pathsM(n-1, m, cache)
    return cache[key]

print(pathsM(2, 3))

# -------------- Tablutaion -----------------

def tabulation_gridTraveller(n, m):
    table = [[0]*m for _ in range(n)]
    
    for i in range(n):
        table[i][0] += 1

    for i in range(1, m):
        table[0][i] += 1

    for i in range(1, n):
        for j in range(1, m):
            table[i][j] += table[i-1][j] + table[i][j-1]
    
    return table[n-1][m-1]


print(tabulation_gridTraveller(50, 50))