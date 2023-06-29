mygenerator = (i for i in range(10) if i % 2 == 0)
for i in mygenerator:
    print(i)

# lll to list
mylist = [i for i in range(10) if i % 2 == 0]

print(list(mygenerator))