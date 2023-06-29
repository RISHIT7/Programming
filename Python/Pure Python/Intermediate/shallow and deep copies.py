import copy
# shallow copy: one level deep, only refeerences of the nested child objects
# deep copy: full independent copy

# org = [0, 1, 2, 3, 4, 5, 6]
# cpy = copy.copy(org) # deep copy
# cpy = org.copy() # shallow copy
# cpy = list(org)
# cpy = org[:]
# cpy[0] = -100
# print(cpy)
# print(org)

org = [[0, 12, 4, 5, 6], [1, 3, 5, 7, 4]]
scpy = org.copy()
scpy[0][0] = -10
dcpy = copy.deepcopy(org)
dcpy[0][0] = -10
print(dcpy)
print(scpy)
print(org)


# shallow copy
class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age


p1 = Person("alex", 27)
p2 = copy.copy(p1)

p2.age = 28

print(p1.age)
print(p2.age)


# deep copy
p3 = Person("Alex", 55)
p4 = Person("Rishit", 27)

class Company():
    def __init__(self, boss, employee):
        self.boss = boss
        self.employee = employee

company = Company(p3, p4)
company_clone = copy.deepcopy(company)
company_clone.boss.age = 56
print(company_clone.boss.age)
print(company.boss.age)