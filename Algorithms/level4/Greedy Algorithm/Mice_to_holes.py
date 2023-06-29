def assignHole(mice, holes):
    if len(mice) != len(holes):
        return "Number of mice and holes is not the same"

    mice.sort()
    holes.sort()

    max_diff = 0

    for i in range(len(mice)):
        if max_diff < abs(mice[i] - holes[i]):
            max_diff = abs(mice[i] - holes[i])

    return max_diff


mice = [4, -4, 2]
holes = [4, 0, 5]

min_time = assignHole(mice, holes)

print(f"The last mouse get's into the hole in {min_time} unit time")