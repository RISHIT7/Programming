from multiprocessing import Pool

def cube(number):
    return number**3
 
if __name__ == "__main__":

    numbers = range(10)
    pool = Pool()

    # map, apply, join, close
    result = pool.map(cube, numbers)
    # pool.apply(cube, numbers(0))

    pool.close()
    pool.join()

    print(result)
