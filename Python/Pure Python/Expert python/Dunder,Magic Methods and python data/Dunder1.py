# x = [1, 2, 4]
# y = [4, 5]

# print(x * 3)

# class Person:
#     def __init__(self, name):
#         self.name = name

# p = Person("tim")
# print(p) # memory address location

class Person():
    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return f"person({self.name})"  # read from blog, dunder methods

    def __mul__(self, x):
        if type(x) is not int:
            raise Exception("Invalid argument, must be int")
        self.name = self.name * x

    def __call__(self, y):
        print(f"This is the input {y}")

    def __len__(self):
        return len(self.name)


p = Person("tim")
p * 4
print(p)

p = Person("tim")
p(4)

print(len(p))