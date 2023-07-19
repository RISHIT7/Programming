# iterable is all of lists, tuples, arrays, etc.

tuple = ("car", "bike", "train")
myit = iter(tuple) # iterator

print(next(myit)) # has next and iter methods
print(next(myit))
print(next(myit))
# stop iteration error

# ---- creating an iterator ------

class Numbers:
    def __iter__(self):
        self.a = 1
        return self
    
    def __next__(self):
        x = self.a
        self.a += 1
        return x
    

myclass = Numbers()
myiter = iter(myclass)

print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
