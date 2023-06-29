"""x = -5
if x < 0:
    raise Exception("x should be positive")

assert (x >= 0), "x is not positive" #Assertion error

try :
    a = 5 / 1
except ZeroDivisionError as e:
    print(e)
else :
    print("Every thing is fine")
finally:
    print("Cleaning up...")"""


class ValueTooHighError(Exception):
    pass

class ValueTooSmallError(Exception):
    def __init__(self, message, value):
        self.message = message
        self.value = value

def test_value(x):
    if x > 100:
        raise ValueTooHighError("Value is too high")
    elif x < 5:
        raise ValueTooSmallError("Value too small", x)
try :
    test_value(1)
except ValueTooHighError as e:
    print(e)
except ValueTooSmallError as e:
    print(e.message, e.value)