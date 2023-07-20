# ---------- Recursive 1 -----------

def print_subset(L, t, i=0, arr = [], ans = []):
    if i < len(L):
            
        print_subset(L, t, i+1, arr + [L[i]])
        print_subset(L, t, i+1, arr)

    ans += [sum(arr)]
    if t in ans:
        return True
    else:
        return False

t = 11
# print(print_subset([7, 3, 2], t))

# --------------- Recursive 2 ---------------

def canSum(t, L):
    if t == 0:
        return True
    if t < 0 :
        return False
    for el in L:
        remainder = t - el
        if canSum(remainder, L) == True:
            return True
    return False

# print(canSum(7, [3, 5, 2, 7]))

# --------------- Memoization --------------

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
            cache[t] = True
            return True, M
    cache[t] = False
    return False, M

print(canSum(12, [1, 5, 13, 8, 2]))

# ------------ Tabulation -------------

def tabulation_canSum(k, L):
    
    table = [[False]*(k+1)]
    table[0] = True
    for i in range(len(table)):
        if table[i] == True:
            for num in L:
                if i + num < len(table):
                    table[i+num] = True
    
    return table[len(table)-1]

# print(tabulation_canSum(14, [7, 3, 2, 5, 8]))