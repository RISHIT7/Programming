def isValidSubsequence(array, sequence):
    i = 0
    for element in sequence:
        if element in array:
          i += 1
    if i == len(sequence):
        print("true")
    else :
        print("false")
    pass

array = [5, 1, 22, 25, 6, -1, 8, 10]
sequence = [1, 6, -1, 11]
isValidSubsequence(array, sequence)