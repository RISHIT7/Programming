# [abc]
# [a][bc] [a][cb]
# [abc][bac][bca] [acb][cab][cba]


# [abcd]
# [abc][d]
# [a][bc][d] [a][cb][d]
# [abc][d] [bac][d] [bca][d] [acb][d] [cab][d] [cba][d]
# now append d in every position

def permutation3(string):
    perm3 = []
    strlist = list(string)
    strlist1 = strlist[0]
    strlist2 = strlist[1:]
    rtslist2 = strlist2[::-1]
    for i in range(len(string)):
        strlist2.insert(i, strlist1)
        rtslist2.insert(i, strlist1)
        perm3.append(''.join(strlist2))
        perm3.append(''.join(rtslist2))
        strlist2.pop(i)
        rtslist2.pop(i)
    return perm3

def permutation4(string):
    perm4 = []
    strlist = list(string)
    strlist1 = strlist[0]
    strlist2 = strlist[1:]
    permutation = permutation3(''.join(strlist2))
    for element in permutation:
        elelist = list(element)
        for i in range(len(string)):
            elelist.insert(i, strlist1)
            perm4.append(''.join(elelist))
            elelist.pop(i)
    return perm4

def permutation5(string):
    perm5 = []
    strlist = list(string)
    strlist1 = strlist[0]
    strlist2 = strlist[1:]
    permutation = permutation4(''.join(strlist2))
    for element in permutation:
        elelist = list(element)
        for i in range(len(string)):
            elelist.insert(i, strlist1)
            perm5.append(''.join(elelist))
            elelist.pop(i)
    print(perm5)

permutation5("ABCDE")