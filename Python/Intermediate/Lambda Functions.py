add10 = lambda x : x + 10
print(add10(5))


mult = lambda x, y: x * y
print(mult(2, 7))

points2D = [(2, 1), (3, 2), (4, 5), (9, 1)]
points2D_sorted = sorted(points2D, key=lambda x: x[1] + x[0])

# map(funct, seq)
a = [1, 2, 3, 4, 5]
b = map(lambda x: x * 2, a) # of [i*2 for i in a]
print(list(b))

a = [1, 2, 3, 4, 5, 6]
c = filter(lambda x: x%2==0, a) # [x forx in a if x%2==0]
from functools import reduce
#reduce func
a = [1, 2, 3, 4, 5, 6]
product_a = reduce(lambda x, y: x*y, a)
print(product_a)