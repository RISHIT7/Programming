from multiprocessing import Queue
from multiprocessing import Process, Array, Lock
import time

def square(numbers, queue):
    for i in numbers:
        queue.put(i**2)

def make_negative(numbers, queue):
    for i in numbers:
        queue.put(-1*i)


if __name__ == "__main__":

    numbers = range(1, 6)
    q = Queue()

    p1 = Process(target=square, args=(numbers, q))
    p2 = Process(target=make_negative, args=(numbers, q))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    while not q.empty():
        print(q.get())