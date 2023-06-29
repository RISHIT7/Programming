def house_robber_memoization(L, n=0, cache = {}):
    key = n
    if key in cache:
        return cache[key]
    if n == len(L) or n == len(L) + 1:
        return 0
    else:
        pick = L[n] + house_robber_memoization(L, n+2, cache)
        notpick = house_robber_memoization(L, n+1, cache)
        cache[key] = max(pick, notpick)
        return cache[key]

print(house_robber_memoization([2, 10, 3, 6, 8, 1, 7]))

def house_robber_tabulation(L):
    table = [[0]*(len(L)+2) for _ in range(len(L)+2)]
    for i in range(2, len(table)):
        for j in range(2, len(table)):
            table[i][j] = max(table[i-1][j-1], L[j-2]+table[i-1][j-2])
    
    return table[len(table)-1][len(table)-1]

print(house_robber_tabulation([2, 10, 3, 6, 8, 1, 7]))
