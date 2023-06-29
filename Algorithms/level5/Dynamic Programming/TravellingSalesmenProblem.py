# TSP
# brute force
# starting and ending point
# (n-1)! permutations
# calc cost of every (n-1)! permutations
# return min cost

# Optimised method

from itertools import permutations
V = 4 
def travel_salesman_problems(graph, s):
    # store all the vertices
    vertex = []
    for i in range(V):
        if i != s:
            vertex.append(i)

    min_path = []
    next_permutation = permutations(vertex)

    for i in next_permutation:
        current_pathweight = 0

        k = s
        for j in i:
            current_pathweight += graph[k][j]
            k = j
        current_pathweight += graph[k][s]
        min_path.append(current_pathweight)
        x = sorted(min_path)

    return x[0]

if __name__ == "__main__":
    graph = [[0, 10, 15, 20],
             [10, 0, 35, 25],
             [15, 35, 0, 30],
             [20, 25, 30, 0]]
    s = 0
    print(travel_salesman_problems(graph, s))