"""
Giraffe Lang
vowels -> g
-----------
dog -> dgg
cat -> cgt
"""

def translate(String):
    translation = ""
    for letter in String:
        if letter in "AEIOUaeiou":
            translation = translation + "g"
        else :
            translation = translation + letter
    
    return translation

print(translate(input("Enter a name: ")))