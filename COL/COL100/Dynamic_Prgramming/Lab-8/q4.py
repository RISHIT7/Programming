def subsest_sum(L, k):
    table = [None]*(k+1)
    table[0] = []

    for el in L:
        for i in range(len(table)):
            if (table[i] != None) and (i + el < len(table)):
                if (table[i+el] == None or el not in table[i+el]) and el not in table[i]:
                    table[i+el] = table[i] + [el]
        print(table)
    return table

print(subsest_sum([7, 2, 5, 3], 14))