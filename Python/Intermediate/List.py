mylist1 = ["banana", "apple", "cherry"]
mylist2 = []
mylist2.insert(0, "Rishit")
mylist2.pop()
mylist2.remove("cherry")
mylist1.clear()

name = ["rishit", "aamod", "rudra", "kathan", "aaryan"]
name.sort()
new_list = sorted(name)
name.reverse()
mylist = [0] * 5
Mylist = [1, 2, 3, 4, 5]
New_list = mylist + Mylist

list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
a = list[1:5]
b = list[1::2]
c = list[::-1]
print(a)

list_org = ["banana", "cherry", "apple"]
list_cpy = list_org.copy()
list_cpy = list(list_org)
list_cpy = list_org[:]

#list comprehension
a = [1,2,3,4,5,6,7]
b = [i*1 for i in a]
