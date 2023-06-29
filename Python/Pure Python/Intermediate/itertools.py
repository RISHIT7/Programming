# itertools: product, permutations, combinations, accumulations, groupby, and infinite iterators
from itertools import count, cycle, repeat
from itertools import groupby
from itertools import combinations_with_replacement, product
from itertools import permutations
from itertools import combinations
from itertools import accumulate
import operator

"""a = [1, 2]
b = [3]
prod = product(a, b, repeat=2) #cartesian product"""

"""a = [1,2,3]
perm = permutations(a, 2) # printing this will print all permutations for the above list
#  the 2 is for the length of output"""


"""a = [1,2,3]
comb = combinations(a, 2)
comb_wr = combinations_with_replacement(a, 2)"""

"""a = [1,2,3,4]
acc = accumulate(a, func=operator.mul)"""
# [1,3,6,10]
# with mul it'll multiply, and for max, it is obv

"""def smallerthan3(x):
    return x < 3

a = [1,2,3,4]
group_obj = groupby(a, key=smallerthan3) # or key=lambda x: x<3
print(group_obj)
for key, value in group_obj:
    print(key, list(value))"""

"""for i in count(10):
    print(i)
    if i == 15:
        break

a = [1, 2, 3]
for i in cycle(a):
    print(i)

a = [1, 2, 3]
for i in repeat(1, 40):
    print(i)"""