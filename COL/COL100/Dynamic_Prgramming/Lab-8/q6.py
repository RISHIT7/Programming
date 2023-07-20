def max_value(V, n, cache = {}):
    key = n
    if key in cache:
        return cache[key]
    if n < 0 :
        return 0
    if n == 0:
        return V[n]
    else:
        pick = V[n] + max_value(V, n-2, cache)
        not_pick = max_value(V, n-1, cache)
        cache[key] = max(pick, not_pick)
    return cache[key]

n = [6, 7, 1, 3, 8, 2, 4]
print(max_value(n, len(n)-1))

def max_value_tabulation(L):
    table = [[0]*(len(L)+2) for _ in range(len(L)+2)]
    for i in range(2, len(table)):
        for j in range(2, len(table)):
            table[i][j] = max(table[i-1][j-1], L[j-2]+table[i-1][j-2])
    
    return table[len(table)-1][len(table)-1]

n = [6, 7, 1, 3, 8, 2, 4]
print(max_value_tabulation(n))
