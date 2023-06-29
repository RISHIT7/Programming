# a11 0   0   0
# a21 a22 0   0
# a31 a32 a33 0
# a41 a42 a43 a44
array = [[1, 0, 0, 0],
         [1, 1, 0, 0],
         [1, 1, 1, 0],
         [1, 1, 1, 1]]


def traverse(matrix):
    marked = set()
    sum = []

    for row in range(len(matrix)):
        for col in range(len(matrix[row])):
            if matrix[row][col] != 0 and (row, col) not in marked:
                cursum = matrix[row][col]
                marked.add((row, col))
                stack = [(row, col)]

                while stack:
                    current = stack.pop()
                    neighbours = getNeighbours(current, matrix)
                    for n in neighbours:
                        y, x =  n
                        if matrix[x][y] != 0 and (y, x) not in marked:
                            marked.add((y, x))
                            cursum += matrix[row][col]
                            stack.append((y, x))
                sum.append(cursum)
    return sum


def getNeighbours(position, matrix):
    y, x = position
    ns = []

    if x < len(matrix[0])-1 and y < len(matrix)-1:
        ns.append((y+1, x+1))
    if y < len(matrix)-1:
        ns.append((y+1, x))
    
    return ns

print(traverse(array))