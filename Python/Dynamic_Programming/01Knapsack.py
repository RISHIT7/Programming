# ----------- Memoization  ------------

def knapsack_memoization(values, weights, k, m=0, cache = {}):
    key = k
    if key in cache:
        return cache[key]
    if m == len(weights):
        return 0
    if k <= weights[m]:
        cache[key] = knapsack_memoization(values, weights, k, m+1)
        return cache[key]
    else:
        pick = values[m] + knapsack_memoization(values, weights, k-weights[m], m+1)
        notpick = knapsack_memoization(values, weights, k, m+1)
        cache[key] = max(pick ,notpick)
    return cache[key]

print(knapsack_memoization([20, 13, 15, 25, 10], [3, 6, 2, 5, 1], 10))

# ------------- Tabulation ---------------

def knapsack_tabulation(values, weights, k):
    table  = [[0]*(k+1) for _ in range(len(weights)+1)]
    
    for i in range(1, len(table)):
        for j in range(1, len(table[0])):
            if weights[i-1] - j > 0:
                table[i][j] = table[i-1][j]
            else:
                table[i][j] = max(values[i-1] + table[i-1][j-weights[i-1]], table[i-1][j])
    return table[len(table)-1][len(table[0])-1]

print(knapsack_tabulation([20, 13, 15, 25, 10], [3, 6, 2, 5, 1], 10))
