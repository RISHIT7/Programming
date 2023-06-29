from doctest import master
from cryptography.fernet import Fernet


def load_key():
    file = open("key.key", "rb")
    key = file.read()
    file.close()
    return key

key = load_key()
fer = Fernet(key)

'''
def write_key():
    key = Fernet.generate_key()
    with open("key.key", "wb") as key_file:
        key_file.write(key)'''


def view():
    with open("Password.txt", 'r') as f:
        for line in f.readlines():
            data = line.rstrip()
            user, passw = data.split("|")
            print("User: " + user, ", " "Password: " +
                  fer.decrypt(passw.encode()).decode())


def add():
    name = input("Account name: ")
    pwd = input("Password: ")

    with open("Password.txt", 'a') as f:
        f.write(name + "|" + fer.encrypt(pwd.encode()).decode() + "\n")


while True:
    mode = input(
        "Would you like to add a new password or view an existing one(view/add) or press Q to quit: ").lower()
    if mode == 'q':
        break

    elif mode == "view":
        view()
    elif mode == "add":
        add()
    else:
        print("Invalid mode")
        continue
