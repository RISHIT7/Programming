# Mad Lib games
"""color = input("Enter a color here: ")
plural_noun = input("Enter a plural noun here: ")
celebrity = input("Enter a celebrity here: ")

print(f"Roses are {color}")
print(f"{plural_noun} are blue")
print(f"I love {celebrity}")
print("And so do you")"""

# Sorting
"""lucky_numbres = ["42", "8", "15", "16", "23"]
lucky_numbres.sort()
print(lucky_numbres)"""

# return key word
"""def cube(num):
    no = num **3
    return no

result = cube(3)
print(result)"""

# a max function
"""def max_num(no1, no2, no3):
    if no1 >= no2 and no1 >= no3:
        return no1
    elif no2 >= no1 and no2 >= no3:
        return no2
    else:
        return no3


print(max_num(2, 5, 8))"""

# guess word
"""secret_word = "giraffe"
guess = ""
guess_count = 0

while guess != secret_word:
    guess = input("Enter guess: ")
    guess_count += 1

print("You win!")"""

# 2D lists and nested loops
"""number_grid = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [0]
]

print(number_grid[0][0])

for row in number_grid:
    for elements in row:
        print(elements)"""

# try/except for error managment
"""try:
    number = int(input("Enter a number: "))
    print(number)
except ZeroDivisionError as err:
    print(err)
except ValueError:
    print("Invalid input")"""

