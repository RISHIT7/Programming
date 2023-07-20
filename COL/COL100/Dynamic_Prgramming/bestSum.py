# ---------------- Recursive ---------------

def bestSum(t, L):
    if t == 0:
        return []
    if t < 0:
        return None
    else:
        shortest = None
        for i, el in enumerate(L):
            remainder = t-el
            A = L[:i] + L[i+1:]
            list = bestSum(remainder, A)
            if list != None:
                combination = list + [el]
                if shortest == None or len(combination) < len(shortest):
                    shortest = combination
    return shortest

print(bestSum(100, [1, 3, 5, 7, 9]))

# --------------- Memoization -----------------

def bestSumM(t, L, cache = {}):
    key = t
    if key in cache:
        return cache[key]
    if t == 0:
        return []
    if t < 0:
        return None
    else:
        shortest = None
        for el in L:
            remainder = t-el
            list = bestSumM(remainder, L, cache)
            if list != None:
                combination = list + [el]
                if shortest == None or len(combination) < len(shortest):
                    shortest = combination
    cache[key] = shortest
    return cache[key]

# print(bestSumM(100, [3, 2, 2, 2, 25]))

# -------------- Tabulation ----------------

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

# print(howSum([7, 3, 2, 5, 8], 14))