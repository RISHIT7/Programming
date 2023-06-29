import numpy as np


np.random.seed(1)
a = np.random.rand(3, 3)
b = np.random.randint(0, 10, 3)
c = np.random.randint(0, 10, (3, 4))
d = np.array([1, 2, 3], [4, 5, 6], [7, 8, 9])
np.random.shuffle(d)
