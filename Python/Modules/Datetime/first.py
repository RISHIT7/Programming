import datetime

time = datetime.datetime.now()


def diet(n):
    print(time)
    print(n)
    l = input("Enter your log: ")
    print(f"you entered the log {l} on {time}")
    with open(r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Modules\Datetime\logs.txt", "a") as f:
        f.write(f"{n} - {l} - {time}\n")
        f.close()
    e = input("Do you want to enter another log (y/n) ? : ")
    while e == 'y':
        l = input("Enter your log: ")
        print(f"you entered the log {l} on {time}")
        with open(r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Modules\Datetime\logs.txt", "a") as f:
            f.write(f"{n} - {l} - {time}\n")
            f.close()
        e = input("Do you want to enter another log (y/n) ? : ")


a = input("ENTER YOUR GYM ID IF YOU'RE A GYM MEMBER: ")
if a == "PASSWORD":
    B = int(input("For Hari press 1: \nFor Rohan press 2: \nFor Sohna press 3: "))
    if B == 1:
        c = int(input("For diet, press1: \nFor exercise, press2:"))
        if c == 1:
            n = "Hari, diet log"
            diet(n)
        else:
            n = "Hari, ex log"
            diet(n)
    elif B == 2:
        c = int(input("For diet, press1: \nFor exercise, press2:"))
        if c == 1:
            n = "Rohan, diet log"
            diet(n)
        else:
            n = "Rohan, ex log"
            diet(n)
    else:
        c = int(input("For diet, press1: \nFor exercise, press2:"))
        if c == 1:
            n = "Sohna, diet log"
            diet(n)
        else:
            n = "Sohna, ex log"
            diet(n)
else:
    print("GET GYM MEMBERSHIP")
