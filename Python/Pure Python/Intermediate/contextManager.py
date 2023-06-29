from threading import Lock

with open(r"hello.txt", "w") as f:
    f.write("some todo...")

# lock = Lock()
# lock.acquire()
# # ....
# lock.release() ####Necessary

lock = Lock()
with lock:
    #....
    pass