import random

a = random.random()
b = random.uniform(1, 10)
c = random.randint(1, 10)
d = random.randrange(1, 10)
e = random.normalvariate(0, 1)  # mu and sigma, satistics

mylist = list("ABCDEFGH")
f = random.choice(mylist)
g = random.sample(mylist, 3)
h = random.choices(mylist, k=3)
i = random.shuffle(mylist)

# kind of like minecraft seeds, random but all numbers in same seeds are same
random.seed(1)
print(random.random())
print(random.randint(1, 10))