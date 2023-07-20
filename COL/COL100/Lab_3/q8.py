def CountOdds(n, count=0):
    if n == 0:
        print(count)
    else:
        if n%2 != 0:
            count += 1
        CountOdds(n//10, count)
    return count

CountOdds(int(input()))