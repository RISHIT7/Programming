marks = [95, 98, 100, "Maths"]
print(marks)  # if we use marks[], instead of marks, then we can use this to print individual marks as in marks[0] which would be 95, also - indeices in python mean beggining from behind, hence marks[-1] would be 100

print(marks[0:2]) # 0,2 is not incuded

for score in marks:
    print(score)