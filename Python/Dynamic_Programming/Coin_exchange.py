# 15, [2, 3, 7] == [7, 3, 3, 2] ans 4
def coin_exchange_memoization(amount, possible_coins, cache = {}):
    key = amount
    if key in cache:
        return cache[key]
    if amount == 0:
        return []
    if amount < 0:
        return None
    shortest = None
    for coins in possible_coins:
        remainder = amount - coins
        target = coin_exchange_memoization(remainder, possible_coins, cache)
        if target != None:
            combination = target + [coins]
            if shortest == None or len(shortest) > len(combination):
                shortest = combination
    cache[key] = shortest
    return cache[key]


print(coin_exchange_memoization(15, [2, 3, 7]))


def coin_exchange_tabulation(k, L):
    table = [None]*(k+1)
    table[0] = []

    for i in range(len(table)):
        for el in L:
            if table[i] != None:
                if i + el < len(table):
                    if table[i+el] == None:
                        table[i+el] = table[i] + [el]
    return table[k]

print(coin_exchange_tabulation(15, [2, 3, 7]))
