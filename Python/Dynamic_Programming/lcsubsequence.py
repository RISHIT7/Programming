def lcs_memoization(w1, w2, i=0, j=0, cache = {}):
    key = (i, j)
    if key in cache:
        return cache[key]
    if i == len(w1) or j == len(w2):
        return 0
    else:
        if w1[i] == w2[j]:
            cache[key]  = 1+lcs_memoization(w1, w2, i+1, j+1)
            return cache[key]
        else:
            cache[key] = max(lcs_memoization(w1, w2, i, j+1), lcs_memoization(w1, w2, i+1, j))
            return cache[key]

print(lcs_memoization("abdacbab", "acebfca"))

def lcs_tabulation(w1, w2):
    table = [[0]*(len(w1)+1) for _ in range(len(w2)+1)]
    
    for i in range(1, len(table)):
        for j in range(1, len(table[0])):
            if w2[i-1] == w1[j-1]:
                table[i][j] = 1+ table[i-1][j-1]
            else:
                table[i][j] = max(table[i-1][j], table[i][j-1])
    return table[len(table)-1][len(table[0])-1]
print(lcs_tabulation("abdacbab", "acebfca"))
