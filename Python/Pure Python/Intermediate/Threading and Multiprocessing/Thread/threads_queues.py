from threading import Thread, current_thread, Lock
from queue import Queue

def worker(q, lock):
    while True:
        value = q.get()

        #processing...
        with lock:
            print(f"in {current_thread().name} got {value}")
            q.task_done()

if __name__ == "__main__":

    q = Queue()
    lock = Lock()
    num_threads = 10

    for i in range(num_threads):
        thread = Thread(target=worker, args=(q,lock))
        thread.daemon=True
        thread.start()
    
    for i in range(1, 21):
        q.put(i)
    
    q.join()

    print("end main") 
"""    q.put(1)
    q.put(2)
    q.put(3)

    first = q.get()
    print(first)

    q.task_done()
    q.join()"""