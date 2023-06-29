from multiprocessing import Process, Value, Lock
import time

def add100(number, lock):
    with lock:
        for i in range(100):
            time.sleep(0.01)
            number.value += 1

if __name__ == "__main__":

    lock = Lock()
    shared_number = Value('i', 0)
    print("Number at beginning is", shared_number.value)

    p1 = Process(target=add100, args=(shared_number,lock))
    p2 = Process(target=add100, args=(shared_number,lock))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    print("Number at end is", shared_number.value)