import logging

logging.basicConfig(level=logging.INFO, filename=r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Intermediate\Logging\log3.log",
                    filemode="w", format="%(asctime)s - %(levelname)s - %(message)s")

try :
    1 / 0
except ZeroDivisionError as e:
    """logging.error(e, exc_info=True)"""
    logging.exception(e)