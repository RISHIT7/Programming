# --------------- Recursive ---------------

def allConstruct(target, List):
    if target == "":
        return [[]]
    
    result = []
    
    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                suffixWays = allConstruct(suffix, List)
                targetWays = [[el]+suffixWay for suffixWay in suffixWays]
                result += targetWays
        except:
            continue
    return result

# print(allConstruct("abcdef", ["ab", "c", "def", "abc", "d", "ef"]))

# --------------- Memoization ---------------

def allConstructM(target, List, cache = {}):
    key = target
    if key in cache:
        return cache[key]

    if target == "":
        return [[]]
    
    result = []
    
    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                suffixWays = allConstructM(suffix, List)
                targetWays = [[el]+suffixWay for suffixWay in suffixWays]
                result += targetWays
        except:
            continue
    cache[key] = result
    return cache[key]

print(allConstructM("abcdef", ["ab", "c", "def", "abc", "d", "ef"]))