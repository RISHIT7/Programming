def riverSizes(matrix):
    marked = set()
    rivers = []

    for row in range(len(matrix)):
        for col in range(len(matrix[row])):
            if matrix[row][col] == 1 and (row, col) not in marked:
                curRiver_len = 1
                marked.add((row, col))
                stack = [(row, col)]

                while stack:
                    current = stack.pop()
                    neighbours = getNeighbours(current, matrix)
                    for n in neighbours:
                        y, x = n
                        if matrix[y][x] == 1 and (y, x) not in marked:
                            marked.add((y, x))
                            curRiver_len += 1
                            stack.append((y, x))

                rivers.append(curRiver_len)
    return rivers


def getNeighbours(position, matrix):

    y, x = position
    ns = []
    if x >= 1:
        ns.append((y, x-1))  # left neighbour

    if x < len(matrix[0])-1:
        ns.append((y, x+1))

    if y >= 1:
        ns.append((y-1, x))
    if y < len(matrix) - 1:
        ns.append((y+1, x))

    return ns

input = [
    [1, 0, 0, 1, 0],
    [1, 0, 1, 0, 0],
    [0, 0, 1, 0, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 1, 1, 0]
]
print(sorted(riverSizes(input)))