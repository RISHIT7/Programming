def mygenerator():
    yield 1
    yield 2
    yield 3


g = mygenerator()

"""value = next(g)
print(value)

value = next(g)
print(value)

value = next(g)
print(value)"""

#  print(sum(g))

#  print(sorted(g))


def countdown(num):
    print("Starting...")
    while num > 0:
        yield num
        num -= 1


cd = countdown(5)

value = next(cd)
print(value)

print(next(cd))
print(next(cd))
print(next(cd))
print(next(cd))