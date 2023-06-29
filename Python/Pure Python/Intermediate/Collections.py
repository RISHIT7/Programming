# collections: Counter, namedtuple, OrdereDict, defaultdict, deque
from collections import namedtuple
from collections import Counter
from collections import OrderedDict
from Collections import defaultdict
from collections import deque

a = "aaaaabbbbccc"
mycounter = Counter(a)
print(mycounter.most_common(1)[0][0])
print(list(mycounter.elements()))

Point = namedtuple("Point", "x, y")
pt = Point(1, -4)
print(pt.x, pt.y)

ordered_dict = OrderedDict()
ordered_dict['a'] = 1
ordered_dict['b'] = 2
ordered_dict['c'] = 3
ordered_dict['d'] = 4

d = defaultdict(int) # or a list or a float, this is to remove a key error
d['a'] = 1
d['b'] = 2

e = deque() # a list but with a direction
e.append(1)
e.append(2)
e.appendleft(3)
e.extendleft([4, 5, 6])
e.rotate(2)
e.rotate(-1)