def nth_ugly(n):
    dpUgly = [0]*n
    dpUgly[0] = 1

    u2 = u3 = u5 = 0

    multiple_2 = 2
    multiple_3 = 3
    multiple_5 = 5

    for i in range(1, n):
        dpUgly[i] = min(multiple_2, multiple_3, multiple_5)

        if dpUgly[i] == multiple_2:
            u2 += 1
            multiple_2 = dpUgly[u2]*2

        if dpUgly[i] == multiple_3:
            u3 += 1
            multiple_3 = dpUgly[u3]*3

        if dpUgly[i] == multiple_5:
            u5 += 1
            multiple_5 = dpUgly[u5]*5

    return dpUgly[n-1]


n = int(input("Enter the index here: "))
print(f"The {n}th ugly number is {nth_ugly(n)}")
