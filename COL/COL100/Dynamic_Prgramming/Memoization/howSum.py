def howSum(t, L, cache = {}):
    if t in cache:
        return cache[t]
    if t == 0:
        return []
    if t < 0:
        return None
    
    for el in L:
        remainder = t - el
        result = howSum(remainder, L, cache)
        if result != None:
            cache[t] = result + [el]
            return cache[t]
    
    cache[t] = None
    return None

print(howSum(14, [7, 3, 2, 5, 8]))