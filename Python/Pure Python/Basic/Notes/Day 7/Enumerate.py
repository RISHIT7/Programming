mylist = [1, 2, 3, 4, 5, 6, 7, 8, 9]

for i, v in enumerate(mylist):
    if i == 2 or i == 4 or i == 6:
        print(v)

print(mylist[2:7:2])