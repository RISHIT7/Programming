def final_balance(t):
    sum = 0
    for el in t:
        if el[0] == "D" and sum >= 0:
            sum += int(el[2::])
        elif el[0] == "W" and sum >=0:
            sum -= int(el[2::])
        elif sum < 0:
            sum = -1
    return sum
        

