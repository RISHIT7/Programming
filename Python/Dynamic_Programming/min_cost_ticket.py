def min_cost_path_memoization(L, cost, n, cache = {}):
    key = n
    if key in cache:
        return cache[key]
    if n <= 0:
        return 0
    else:
        if L[n-1] == True:
            value_ones = cost[0] + min_cost_path_memoization(L, cost, n-1)
            value_sevens = cost[1] + min_cost_path_memoization(L, cost, n-7)
            value_thirties = cost[2] + min_cost_path_memoization(L, cost, n-30)
            cache[key] = min(value_ones, value_sevens, value_thirties)
        else:
            cache[key] = min_cost_path_memoization(L, cost, n-1)
            return cache[key]
    return cache[key]

L = [False, True, False, True, False, False, False, False, True, True, False, False, False, False, False, False, False, False, False, False, False, False, True, True, False, False, False, False, True, False, False, True]

print(min_cost_path_memoization(L, [4, 10, 25], 32))

def min_cost_path_tabulation(train_days, costs, n):
    dp = [0]*n
    for i in range(len(dp)):
        if train_days[i] == False:
            dp[i] = (dp[i-1] if i-1 >= 0 else 0)
        else:
            day_cost = costs[0] + (dp[i-1] if i-1 >= 0 else 0)
            week_cost = costs[1] + (dp[i-7] if i-7 >= 0 else 0)
            month_cost = costs[2] + (dp[i-30] if i-30 >= 0 else 0)
            dp[i] = min(day_cost, week_cost, month_cost)
    return dp[n-1]

print(min_cost_path_tabulation(L, [4, 10, 25], 32))
