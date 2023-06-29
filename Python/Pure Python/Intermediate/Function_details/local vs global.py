# number = 0
# def foo():
#     global number
#     number = 3
#     x = number
#     print("number inside function " + str(x))

# foo()
# print(number)



number = 0
def foo():
    number = 3
    x = number
    print("number inside function " + str(x))

foo()
print(number)