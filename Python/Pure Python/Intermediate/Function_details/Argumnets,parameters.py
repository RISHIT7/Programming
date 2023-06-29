# def function(parameter):
#     # code
#     pass

# function("argument")



# def fioo(a, b, c, d=0):  # d is a default argument, must be at the end
#     print(a, b, c, d)

# fioo(a=1, c=3, b=2)  # kwargs, (args, kwargs) works but not vice versa
# fioo(1, 2, 3)  # args



# def foo(a, b, *args, **kwargs): # args are stored as tuple, kwargs are stored as dict
#     print(a, b)
#     for arg in args:
#         print(arg)
#     for key in kwargs:
#         print(key, kwargs[key])

# foo(1, 2, 3, 4, 5, six=6, seven=7, eight=8)



# def foo(a, b, *, c, d): # args are stored as tuple, kwargs are stored as dict
#     print(a, b, c, d)

# foo(1, 2, c=3, d=4)



def foo(a, b, c):
    print(a, b, c)

mylist = [1, 2, 3]
foo(*mylist)

mydict = {'a': 1, 'b': 2, 'c':3} # keys and length must match
foo(**mydict)