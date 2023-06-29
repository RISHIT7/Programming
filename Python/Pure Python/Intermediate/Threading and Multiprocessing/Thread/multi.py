from threading import Thread
import time

database_value = 0

def square_numbers():
    for i in range(100):
        i**2
        time.sleep(0.1)

if __name__=="__main__":
    threads = []
    num_threads = 10

    #create processes
    for i in range(num_threads):
        t = Thread(target=square_numbers)
        threads.append(t)

    #start
    for t in threads:
        t.start()

    # join
    for t in threads:
        t.join()

    print("end main")