# serialisation and deserialisation

# used to convert any type of an item to bytes
# mainly used in machine learning, used to "flatten the data"

# used to convert data from 2D format to 1D format and store it, then convert it etc.

import pickle

mydicts = {'1':'a', '2':'b'}

with open("pickle_file.txt", "wb") as pf:
    pickle.dump(mydicts, pf)

pickle_file = open("pickle_file.txt", "rb")
new_dict = pickle.load(pickle_file)

print(new_dict)