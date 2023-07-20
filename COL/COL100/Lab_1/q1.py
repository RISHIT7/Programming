FirstNum = float(input())
SecondNum = float(input())

x = (FirstNum**2 + SecondNum**2)**(1/2)

print("Addition: " + str(FirstNum+SecondNum))
print("Subtraction: " + str(FirstNum-SecondNum))
print("Multiplication: " + str(FirstNum*SecondNum))
if SecondNum == 0:
    print("Division: Cannot be divided")
else:
    print("Division: " + str(FirstNum/SecondNum))
print("Exponentiation: " + str(FirstNum**SecondNum))
print("L2-norm: " + str(x))
