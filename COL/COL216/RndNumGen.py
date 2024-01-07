import numpy as np

with open(r"C:\Users\rishi\Desktop\Programming\COL\COL216\a_and_b.txt", "w") as file:
    for _ in range(500):
        a = bin(np.random.randint(0, 2**16, dtype = "int64"))[2:].zfill(16)
        b = bin(np.random.randint(0, 2**16, dtype = "int64"))[2:].zfill(16)
        str_fin = "\"" + a + "\"" + ", " + "\"" + b + "\"\n"
        file.write(str_fin)

file.close()