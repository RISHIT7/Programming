def canSum(t, L, cache = {}, M = []):
    key = t
    if key in cache:
        return cache[key]
    if t == 0:
        return True
    if t < 0 :
        return False
    for el in L:
        remainder = t - el
        if canSum(remainder, L, cache, M) == True:
            M.append(el)
            cache[key] = True
            return True, M
    cache[key] = False
    return False, M

print(canSum(7, [3, 5, 2, 7]))