from multiprocessing import Process
import os

def square_numbers():
    for i in range(1000):
        i**2

if __name__ == "__main__":
    processes = []
num_processes = os.cpu_count()

#create processes
for i in range(num_processes):
    p = Process(target=square_numbers)
    processes.append(p)

#start
for p in processes:
    p.start()

# join
for p in processes:
    p.join()

print("end main")
