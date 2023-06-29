keydict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
key = input("Enter Roman numeral here: ")


def romanToInt(keydict, key):
    keylist = list(key)
    keyvalue = []
    value = 0
    for element in keylist:
        keyvalue.append(keydict[element])
    print(keylist)
    print(keyvalue)

    largest = 0
    for i in keyvalue[::-1]:
        if i >= largest:
            largest = i
            value += i
        else :
            value -= i

    return value

def checkingValidity(key):
    i = 0
    if len(key) > 3:
        while i < len(key)-3:
            if key[i] == key[i+1] and key[i+1] == key[i+2] and key[i+2] == key[i+3]:
                print("Not a valid number!")
            i += 1
        else:
            print(romanToInt(keydict, key))
    else :
        print(romanToInt(keydict, key))

print(key)

checkingValidity(key)