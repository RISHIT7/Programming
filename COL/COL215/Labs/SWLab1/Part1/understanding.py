# --------- Gates -----------
# PRIMARY_INPUTS A B
# PRIMARY_OUTPUTS E F
# INTERNAL_SIGNALS C D
# INV A C
# AND2 C B D
# NAND2 C D E
# INV D F

# ------------ Time Delays --------
# NAND2 3
# AND2 4
# NOR2 3.5
# OR2 4.5
# INV 2

# -------------- Output -------------
# E 9
# F 8

# ------------- algo ----------------

"""
first take in the input from the file
then make two dictionaries
one that links the gate to the input
other that links the input to the output

now from the required output go back and 
check the inputs as well, and similarly keep 
going back till you reach the input

now add the gates you found
"""

"""
A 2 -C
C*B 4 D
C*D 3 -E
D 2 -F

[[A], 2, C]
[[C, B], 4, D]
[[C, D], 3, E]
[[D], 2, F]

A --> C
C --> D <-- B
C --> E <-- D
D --> F


"""

# def checker(array):
#     input_array = array[0]
#     for el in input_array:
#         if el not in ["A", "B"]:
#             return False
#     return True

# print(checker([["A"], 2, "C"]))

# def return_inputs(array):
#     return array[0]

# def find_output(el):
#     pass

# def find_input(master_array, array):
#     inputs = return_inputs(array)
#     if (checker(array)):
#         return array[1]
#     else:
#         for el in inputs:
#             if (el != "A" and el != "B"):
#                 list = find_output(el)
#                 array[0].remove(el)
#                 array[1] += list[1]