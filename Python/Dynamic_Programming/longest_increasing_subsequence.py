def lin_memoization(L, i=0, prev = float("-inf"), cache = {}):
    key = (i, prev)
    if key in cache:
        return cache[key]
    if i == len(L):
        return 0
    elif L[i] <= prev:
        cache[key] = lin_memoization(L, i+1, prev, cache)
        return cache[key]
    else:
        cache[key] = max(1+lin_memoization(L, i+1, L[i], cache),lin_memoization(L, i+1, prev, cache))
        return cache[key]
    
n = [7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7]
print(lin_memoization([7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7]))

def lin_tabulation(L):
    pass