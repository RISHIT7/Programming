def paths(m, n):
    row = [1]*n
    print(row)
    for i in range(m-1):
        newRow = [1]*n
        for j in range(n-2, -1, -1):
            newRow[j] = newRow[j+1] + row[j]
        row = newRow
        print(row)
    return row[0]

print(paths(3, 3))