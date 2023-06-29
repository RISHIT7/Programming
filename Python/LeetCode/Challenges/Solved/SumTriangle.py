array = [[1, 0, 0],
         [2, 1, 0],
         [1, 2, 3]]

result = []
stack = []
sum = 0
for i, l in enumerate(array):
    stack.append(l[0])
print(stack)
for i in stack:
    sum += i
result.append(sum)
print(max(result))
