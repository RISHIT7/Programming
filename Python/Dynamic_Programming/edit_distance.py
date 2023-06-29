def edit_distance_memoization(w1, w2, i=0, j=0, cache = {}):
    key = (i, j)
    if key in cache:
        return cache[key]
    if i == len(w1):
        return len(w2)-j
    elif j == len(w2):
        return len(w2)-i
    elif w1[i] == w2[j]:
        cache[key] = edit_distance_memoization(w1, w2, i+1, j+1, cache)
        return cache[key]
    else:
        cache[key] = 1+min(edit_distance_memoization(w1, w2, i+1, j+1, cache), edit_distance_memoization(w1, w2, i, j+1, cache), edit_distance_memoization(w1, w2, i+1, j, cache))
        return cache[key]

# print(edit_distance_memoization("inside", "index"))

def edit_distance_tabulation(w1, w2):
    table = [[0]*(len(w1)+1) for _ in range(len(w2)+1)]
    for i in range(len(table)):
        table[i][0] = i
    for j in range(len(table[0])):
        table[0][j] = j
    print(table)
    for i in range(1, len(table)):
        for j in range(1, len(table[0])):
            if w1[j-1] == w2[i-1]:
                table[i][j] = min(table[i-1][j], table[i-1][j-1], table[i][j-1])
            else:
                table[i][j] = 1 + min(table[i-1][j], table[i-1][j-1], table[i][j-1])
    return table

print(edit_distance_tabulation("inside", "index"))