x = [[1, 2],
     [3, 4]]

y = [[2, 3],
     [3, 4]]

result = [[0, 0],
          [0, 0]]

# iteration through rows of x
for i in range(len(x)):
    # iteration throough columns of y
    for j in range(len(y[0])):
        # iteration of rows of y and columns of x
        for k in range(len(y)):
            result[i][j] += x[i][k]*y[k][j]

print(result[0])
print(result[1]) 