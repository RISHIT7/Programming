def get_fashionably_late(students):
    students = students[::-1]
    ans = []
    for i in range(1, len(students)//2):
        ans.append(students[i])
    return ans[::-1]

