def canConstructM(target, List, cache = {}):
    key = target
    if key in cache:
        return cache[key]
    if target == "":
        return True
    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                bool = canConstructM(suffix, List, cache)
                if bool:
                    cache[key] = bool
                    return cache[key]
        except:
            continue

    cache[key] = False
    return cache[key]

print(canConstructM("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
                    ["e", 
                     "ee", 
                     "eee", 
                     "eeee", 
                     "eeeee", 
                     "eeeeee"]))