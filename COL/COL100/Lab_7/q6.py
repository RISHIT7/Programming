def return_ABC(el, a, b, c):
    if a > c and b > c:
        c = max(c, el)
    elif c > b and a > b:
        b = max(b, el)
    elif b > a and c > a:
        a = max(a, el)
    elif a == b or a == c:
        a = max(a, el)
    elif b == c:
        b = max(b, el)
    return [a, b, c]

def get_triplet(L):
    a = b = c = 1
    i = 0
    while i < len(L):
        list = return_ABC(L[i], a, b, c)
        a = list[0]
        b = list[1]
        c = list[2]
        i += 1

    tup = (list[0], list[1], list[2])
    return tup

print(get_triplet([19, 5, 8, 21, 0, 1, 16, 4, 3, 2]))