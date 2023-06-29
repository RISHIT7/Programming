# finding the 15th ugly number, bottom up method for dynamic uproach
# if number prime factorizes to powers of 2, 3, 5 it is UGLY
# by convention 1 is ugly
def successive_div(x, y):
    while x%y == 0:
        x = x//y
    return x

# Function for checking if a number is ugly or not
def ugly_check(num):
    num = successive_div(num, 2)
    num = successive_div(num, 3)
    num = successive_div(num, 5)
    if num == 1:
        return True
    else:
        return False

def nth_ugly(n):
    i = 1
    # ugly number count
    counter = 1

    # Looping through all intergers util ugly count becomes n
    while n > counter:
        i += 1
        if ugly_check(i):
            counter += 1
    return i

n = int(input("Enter the index here: "))
print(f"{n}th ugly number is {nth_ugly(n)}")