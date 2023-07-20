def get_valid_passwords(passwords):
    ans = []
    for password in passwords:
        CHAR = False
        LETTER = False
        NUM = False
        SIZE = False
        if 6 <= len(password) <= 12:
            SIZE = True
        for char in password:
            if char in ['#','$','@']:
                CHAR = True
        for letter in password:
            if letter in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']:
                LETTER = True
        for num in password:
            if num in ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']:
                NUM = True
        if CHAR and LETTER and NUM and SIZE:
            ans.append(password)
        else:
            pass
    return ans

print(get_valid_passwords(["2We334$5", "a", "F1#", "2w3E*", "ABd1234@1"]))