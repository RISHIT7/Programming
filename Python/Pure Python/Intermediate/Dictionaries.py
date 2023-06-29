mydict1 = {"name": "Max",  "age":28, "city":"New York"}

mydict2 = dict(name="Mary", age="27", city="Boston")

mydict1["email"] = "rishit@gmail.com"

for key in mydict1.keys():
    print(key)

for value in mydict1.values():
    print(value)

for key, value in mydict1.items():
    print(key, value)

mydict1.update(mydict2)