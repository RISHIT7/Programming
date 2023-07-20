# -------------- Recursive --------------

def canConstruct1(target, List, packet = ""):
    if packet == target:
        return True
    if len(packet) > len(target):
        return False
    else:
        for el in List:
            string = packet + el
            bool = canConstruct1(target, List, string)
            if bool:
                return True
    return False

# print(canConstruct1("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]))

def canConstruct2(target, List):
    if target == "":
        return True
    for el in List:
        try:
            if target.index(el) == 0:
                suffix = target[len(el):]
                if canConstruct2(suffix, List):
                    return True
        except:
            pass

    return False

# print(canConstruct2("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]))

# -------------- Memoization --------------

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