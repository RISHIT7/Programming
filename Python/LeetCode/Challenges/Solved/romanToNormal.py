keydict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
key = input("Enter Roman numeral here: ")

def romanToInt(keydict, key):
    keylist = list(key)
    print(keylist)
    keylist = keylist[::-1]
    keyvalue = []
    for element in keylist:
        keyvalue.append(keydict[element])
    print(keyvalue[::-1])
    value = 0
    
    i = 0
    if len(keylist)%2 == 0:
        while i < len(keylist):
            if value <= keyvalue[i]:
                value += keyvalue[i]
            else :
                value -= keyvalue[i]
            i += 1

    else :
        i += 1
        value += keyvalue[0]
        while i < (len(keylist)):
            if value <= keyvalue[i]:
                value += keyvalue[i]
            else :
                value -= keyvalue[i]
            print(value)
            i += 1

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

checkingValidity(key)