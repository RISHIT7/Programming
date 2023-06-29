import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

sales = pd.read_csv(
    r"C:\Users\rishi\OneDrive\Desktop\Programming\DA and DS\data\sales-data.csv",
    parse_dates=["Date"]
)
# print(sales)
# print(sales.shape)
# print(sales.info())
# print(sales.describe())
print(sales["Unit_Cost"].describe())
