import math

Type = input("Enter angle type, deg/rad: ")
Oper = input("Enter the Operator here from (sin, cos, tan): ")
Arg1 = input("Enter Angle here: ")
Arg2 = int(Arg1) * math.pi / 180

if Type == "deg":
    if Oper == "sin":
        print(math.sin(Arg2))
    elif Oper == "cos":
        print(math.cos(Arg2))
    elif Oper == "tan":
        print(math.tan(Arg2))
else :
    if Oper == "sin":
        print(math.sin(Arg1))
    elif Oper == "cos":
        print(math.cos(Arg1))
    elif Oper == "tan":
        print(math.tan(Arg1))