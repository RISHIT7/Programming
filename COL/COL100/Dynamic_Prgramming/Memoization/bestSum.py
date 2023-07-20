def bestSum(L, k, cache = {}):
    key = k
    if key in cache:
        return cache[key]
    if k == 0: 
        return []
    if k < 0 : 
        return None
    else:
        shortest= None
        for el in L:
            remainder = k - el
            list = bestSum(L, remainder, cache)
            if list != None:
                combinations = list + [el]
                if shortest == None or len(shortest) > len(combinations):
                    shortest = combinations
    cache[key] = shortest
    return shortest

print(bestSum([1, 2, 6, 25], 100))