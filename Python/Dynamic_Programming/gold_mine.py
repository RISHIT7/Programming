def gold_mine_memoization(mine):
    max_gold = 0
    cache = {}
    for i in range(len(mine[0])):
        max_gold = max(max_gold, solve(mine, 0, i, cache))
    return max_gold


def solve(mine, i, j, cache):
    n = len(mine)
    m = len(mine[0])
    key = (i, j)
    if key in cache:
        return cache[key]
    if i == n or j < 0 or j == m:
        return 0
    else:
        cache[key] = mine[i][j] + max(solve(mine, i+1, j-1, cache), solve(mine, i+1, j, cache), solve(mine, i+1, j+1, cache))
        return cache[key]


m = [[3, 2, 12, 15, 10],
     [6, 19, 7, 11, 17],
     [8, 5, 12, 32, 21],
     [3, 20, 2, 9,  7]]
# print(gold_mine_memoization(m))

def gold_mine_tabulation(m):
    table = [[0]*len(m[0]) for _ in range(len(m))]
    for i in range(len(table[0])):
        table[0][i] = m[0][i]
    for i in range(1, len(table)):
        for j in range(len(table[0])):
            if j == 0:
                table[i][j] = m[i][j] + max(table[i-1][j], table[i-1][j+1])
            if j == len(table[0])-1:
                table[i][j] = m[i][j] + max(table[i-1][j], table[i-1][j-1])
            else:
                table[i][j] = m[i][j] + max(table[i-1][j-1], table[i-1][j], table[i-1][j+1])
    return table[len(table)-1][len(table[0])-1]

print(gold_mine_tabulation(m))
