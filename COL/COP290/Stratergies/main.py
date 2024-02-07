import sys
from datetime import date
import pandas as pd
from datetime import date
# pyarrow, h5py, tables -> (pytables), feather-format -> (feather), fastavro -> (avro), seaborn, matplotlib

# ------------------------------------ generation of data frame --------------------------------------------
def generate_dataframe(to_date, symbol):
    from jugaad_data.nse import stock_df
    df = pd.DataFrame(stock_df(symbol=symbol, from_date=date(to_date.year-int(sys.argv[2]),to_date.month,to_date.day), to_date=date(to_date.year,to_date.month,to_date.day), series="EQ"))
    df = df[[ "DATE", "OPEN", "CLOSE", "HIGH","LOW", "LTP", "VOLUME", "VALUE","NO OF TRADES"]]
    return df


# ----------------------------------------------- pickle --------------------------------------------------------
def write_pickle(DATA, symbol):
    pd.to_pickle(DATA, symbol + ".pkl")

# -------------------------------------------------------- MAIN -----------------------------------------------------------------------
def main():
    today = date.today()
    argument = sys.argv[1]

    DATA = generate_dataframe(today, argument)
    write_pickle(DATA, "Stocks/" + argument)


if __name__ == "__main__":
    main()