def func(x):
    if x == 1:
        def rv():
            print("X is equal to 1")
    else:
        def rv():
            print("X is not equal to 1")
    return rv


new_func = func(3)
new_func()