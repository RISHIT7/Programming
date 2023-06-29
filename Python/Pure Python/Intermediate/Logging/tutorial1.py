import logging

logging.basicConfig(level=logging.INFO,
                    filename=r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Intermediate\Logging\log1.log", filemode="w",
                    format="%(asctime)s - %(levelname)s - %(message)s") #  this can be read from the python blog

logging.debug("debug")
logging.info("info")
logging.warning("warning")
logging.error("error")
logging.critical("critical")