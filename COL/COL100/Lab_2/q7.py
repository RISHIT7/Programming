s = input()

Words = 0
Spaces = 0
Uppercase = 0
Lowercase = 0

for letter in s:
    if letter == " ":
        Spaces += 1
    elif letter.upper() == letter:
        Uppercase += 1
    elif letter.upper() != letter:
        Lowercase += 1

print(f"Words: {Spaces+1}")
print(f"Spaces: {Spaces}")
print(f"Uppercase: {Uppercase}")
print(f"Lowercase: {Lowercase}")
