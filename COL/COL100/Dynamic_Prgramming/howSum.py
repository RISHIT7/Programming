# ---------- Recursive ------------

def howSum(t, L):
    if t == 0:
        return []
    if t < 0:
        return None
    
    for el in L:
        remainder = t - el
        result = howSum(remainder, L)
        if result != None:
            return result + [el]
    
    return None

# print(howSum(7, [7, 3, 2, 5]))

# -------------- Memoization -----------------

def howSum(t, L, cache = {}):
    if t in cache:
        return cache[t]
    if t == 0:
        return []
    if t < 0:
        return None
    
    for i, el in enumerate(L):
        remainder = t - el
        List = L[:i] + L[i+1:]
        result = howSum(remainder, List, cache)
        if result != None:
            cache[t] = result + [el]
            return cache[t]
    
    cache[t] = None
    return None

print(howSum(14, [7, 3, 2, 5, 8]))

# ------------- howSum --------------

def tabulation_canSum(k, L):
    
    table = [[False]*(k+1) for _ in range(len(L)+1)]

    for i in range(len(L)+1):
        table[i][0] = True

    for i in range(len(table)):
        for j in range(len(table[0])):
            if i+1 < len(table) and table[i][j] == True:    
                var = j+L[i]
                if i+1 < len(table) and var < len(table[0]):
                    table[i+1][var] = True
            if i-1 > 0 and table[i-1][j] == True:
                table[i][j] = True

    return tabulation_howSum(table, len(table)-1, len(table[0])-1, L)

def tabulation_howSum(table, n, m, L, M = []):
    if m == 0:
        return M
    if table[n][m] == True:
        M.append(L[n-1])
        return tabulation_howSum(table, n-1, m-L[n-1], L, M)
        

# print(tabulation_canSum(7, [5, 2]))