def remove_common(a, b):
    ans = []
    for i in range(len(a)):
        if a[i] not in b:
            ans.append(a[i])
        else:
            b.remove(a[i])
    return [ans, b]

