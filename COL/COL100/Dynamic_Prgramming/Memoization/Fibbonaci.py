def fib(n, cache = {}):
    key = n
    if key in cache:
        return cache[key]
    if n == 1:
        return 1
    if n == 0:
        return 0
    else:
        k = fib(n-1, cache) + fib(n-2, cache)
        cache[key] = k
        return cache[key]

print(fib(50))