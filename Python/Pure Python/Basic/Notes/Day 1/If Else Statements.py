age = 19

if age >= 18:
    print("you are an adult")
    print("you can vote")  # Proper indentation is necessary
elif age < 18 and age > 3:
    print("you are in school")
else:
    print("you are a child")

print("Thank you")  # As this print is written below the if statement, this print will be printed regardless of the preceeding statemnt being true or false
