def allConstruct(target, List, cache = {}):
    if target in cache:
        return cache[target]

    if target == "":
        return [[]]
    
    result = []

    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                suffixWays = allConstruct(suffix, List, cache)
                targetWays = [[el] + suffixWay for suffixWay in suffixWays]
                result += targetWays
        except:
            continue

    cache[target] = result
    return cache[target]

print(allConstruct("abcdef", ["ab", "c", "def", "abc", "d", "ef"]))