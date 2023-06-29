import timeit
import sys
mytuple = ("max", 28, "Boston")
# ("max")is not a tuple but a string
# ("max", ) is a tuple

item = mytuple[0]
print(len(mytuple))
print(mytuple.count("max"))
print(mytuple.index("Boston"))

my_list = list(mytuple)
mytuple2 = tuple(my_list)

a = (1, 2, 3, 4, 5, 6, 7, 8, 9, 0)
b = a[2:5]
b = a[::2]
b = a[::-1]

name, age, city = mytuple

c = (0, 1, 2, 3, 4, 5)
i1, *i2, i3 = c

d = [0, 1, 2, "hello", True]
e = (0, 1, 2, "hello", True)
print(sys.getsizeof(d), "bytes")
print(sys.getsizeof(e), "bytes")

print(timeit.timeit(stmt="[0,1,2,3,4,5]", number=1000000))
print(timeit.timeit(stmt="(0,1,2,3,4,5)", number=1000000))
