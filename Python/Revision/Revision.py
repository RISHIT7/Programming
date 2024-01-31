a = 0b0000
b = 0b0000
Iter = []
for n in range(1, 257):
    c = a + b
    a_str = bin(a)[2:].zfill(4)
    b_str = bin(b)[2:].zfill(4)
    c_str = bin(c)[2:].zfill(5)
    
    b += 1
    if (n%16 == 0 and n != 0):
        b = 0
        a += 1
    
    comb_str = a_str + b_str + c_str
    res_str = ""
    for el in comb_str:
        res_str += el + "  "
    res_str += "\n"
    Iter.append(res_str)
    
with open('Test.txt', 'w') as file:
    file.writelines(Iter)
file.close()