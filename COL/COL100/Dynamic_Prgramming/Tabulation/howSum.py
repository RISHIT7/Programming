def howSum(L, k):
    table = [None]*(k+1)
    table[0] = []

    for i in range(len(table)):
        if table[i] != None:
            for el in L:
                if i + el < len(table):
                    List = table[i] + [el]
                    if table[i+el] == None or len(table[i+el]) > len(List):
                        table[i+el] =  List
    print(table)
    return table[len(table)-1]

print(howSum([7, 3, 2, 5, 8], 14))