import logging

logging.basicConfig(level=logging.INFO,
                    filename=r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Intermediate\Logging\log2.log", filemode="w",
                    format="%(asctime)s - %(levelname)s - %(message)s") #  this can be read from the python blog

x = 2
logging.info(f"the value of var is {x}")
