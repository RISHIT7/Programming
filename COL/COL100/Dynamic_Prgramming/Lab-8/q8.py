def arrange(L):
    key = []
    for i in range(len(L)):
        key.append(i+1)
    
    for i in range(len(L)-1):
        for j in range(len(L)-1-i):
            if L[j] > L[j+1]:
                L[j], L[j+1] = L[j+1], L[j]
                key[j], key[j+1] = key[j+1], key[j]
    return key