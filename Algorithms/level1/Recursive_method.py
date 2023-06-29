### recursion ###

# def getFactorial(n):
#     mult = n
#     if n > 1:
#         mult *=  getFactorial(n-1)
#     if n == 0:
#         mult = 1
#     return mult
# i = int(input("Enter the number here: "))
# print(f"{i}! is {getFactorial(i)}")

### Basic permutation calculator ###

def Permute(string, pocket=""):
    if len(string) == 0:
        print(pocket)
 
    else:
        for i in range(len(string)):
            letter = string[i]
            front = string[0:i]
            back = string[i+1:]
            together = front + back
            Permute(together, letter + pocket)

Permute("ABCD") # only works for words with no common letters

# or use itertools permutations lol, but use vanilla in interviews