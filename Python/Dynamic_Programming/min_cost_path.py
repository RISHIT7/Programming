def min_cost_path_memoization(M, m=0, n=0, cache = {}):
    key = (m, n)
    if key in cache:
        return cache[key]
    if m == len(M) or n == len(M[0]):
        return 0
    elif m == len(M)-1:
        cache[key] = M[m][n] + min_cost_path_memoization(M, m, n+1)
        return cache[key]
    elif n == len(M[0])-1:
        cache[key] = M[m][n] + min_cost_path_memoization(M, m+1, n)
        return cache[key]
    else:
        bottom_move = M[m][n] + min_cost_path_memoization(M, m+1, n)
        right_move = M[m][n] + min_cost_path_memoization(M, m, n+1)
        cache[key] = min(bottom_move, right_move)
    return cache[key]

M = [[3, 2, 12, 14, 15],
     [6, 9, 7, 11, 1],
     [8, 5, 12, 14, 14]]
print(min_cost_path_memoization(M))

def min_cost_path_tabulation(M):
    table = [[0]*(len(M[0])) for _ in range(len(M))]
    table[0][0] = M[0][0]
    for i in range(1, len(M[0])):
        table[0][i] = M[0][i]+table[0][i-1]
    for i in range(1, len(M)):
        table[i][0] = M[i][0]+table[i-1][0]

    for i in range(1, len(M)):
        for j in range(1, len(M[0])):
            table[i][j] = M[i][j] + min(table[i-1][j], table[i][j-1])
    
    return table[-1][-1]
print(min_cost_path_tabulation(M))
