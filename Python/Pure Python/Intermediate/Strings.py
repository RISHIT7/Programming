mystring = """Hello 
World"""

myString = """ Hello \
World"""

char = myString[1] # char = character
substrings = mystring[1:5]
reverse = mystring[::-1]
greeting = "hello"
for i in greeting:
    print(i)
#.strip() will strip of empty spaces

my_string = "how,are,you,doing"
my_list = my_string.split(",")
newstring = " ".join(my_list)

var = 3.14159
mYstring = "the variable is %f" %var # NOT similar to C as in C we use &
mysTring = "the variable is {}".format(var)
mystRing = f"the variable is {var}"
print(mYstring)
print(mysTring)
print(mystRing)