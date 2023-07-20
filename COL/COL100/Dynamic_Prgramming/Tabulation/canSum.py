def tabulation_canSum(k, L):
    
    table = [[False]*(k+1)]
    table[0] = True
    for i in range(len(table)):
        if table[i] == True:
            for num in L:
                if i + num < len(table):
                    table[i+num] = True
    
    return table[len(table)-1]

print(tabulation_canSum(14, [7, 3, 2, 5, 8]))