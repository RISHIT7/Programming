# -------------- Recursive ---------------

def canCount(target, List):
    if target == "":
        return 1
    Sum = 0
    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                Sum += canCount(suffix, List)
        except:
            continue
    return Sum

# print(canCount("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
#                     ["e", 
#                      "ee", 
#                      "eee", 
#                      "eeee", 
#                      "eeeee", 
#                      "eeeeee"]))

# -------------- Memoization ---------------

def canCountM(target, List, cache = {}):
    key = target
    if key in cache:
        return cache[key]

    if target == "":
        return 1

    Sum = 0

    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                Sum += canCountM(suffix, List, cache)
        except:
            continue
    
    cache[key] = Sum
    return cache[key]

print(canCountM("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
                    ["e", 
                     "ee", 
                     "eee", 
                     "eeee", 
                     "eeeee", 
                     "eeeeee"]))