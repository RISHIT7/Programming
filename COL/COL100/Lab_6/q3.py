def count_pairs(w):
    count = 0
    for i in range(len(w)):
        for j in range(i+1, len(w)):
            if w[i] == w[j][::-1]:
                count += 1
        w[i] = 0
    return count

