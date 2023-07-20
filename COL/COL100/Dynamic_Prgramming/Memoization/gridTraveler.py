def paths(n, m, cache={}):
    key = (n, m)
    if key in cache:
        return cache[key]
    if n == 0 or m == 0:
        return 0
    if n == 1 and m == 1:
        return 1
    else:
        k = paths(n-1, m, cache) + paths(n, m-1, cache)
        cache[key] = k
        return cache[key]

print(paths(3, 3))