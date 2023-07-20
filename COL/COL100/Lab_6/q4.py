def concat_chars_nums(chars, n):
    ans = []
    for i in range(1, n+1):
        for el in chars:
            k = el + str(i)
            ans.append(k)
    return ans

