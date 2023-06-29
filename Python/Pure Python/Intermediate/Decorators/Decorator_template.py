import functools

def start_end_decorator(func):

    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print("Start")
        result = func(*args, **kwargs)
        print("end")
        return result
    return wrapper

@start_end_decorator
def add5(x):
    return x + 5

print(help(add5(5)))
print(add5.__name__)