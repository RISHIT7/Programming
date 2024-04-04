import pandas as pd
import seaborn as sns
sns.set_theme(style='darkgrid')

def main():
    # ----------------------------------- Importing Data --------------------------------
    DATA = pd.read_csv('../data/raw_data/student-mat.csv')

    # ---------------------------------- Preprocessing -------------------------------------
    variables = ["school","sex","address","famsize","Pstatus","Mjob","Fjob","reason","guardian","schoolsup","famsup","paid","activities","nursery","higher","internet","romantic"]
    DATA = pd.get_dummies(data=DATA, 
                        prefix=variables,
                        columns=variables,
                        dtype=int)
    DATA.drop_duplicates()
    DATA = DATA.drop(columns=["school_MS", "sex_F", "address_U", "famsize_GT3", "Pstatus_A", "schoolsup_no", "famsup_no", "paid_no", "activities_no", "nursery_no", "higher_no", "internet_no", "romantic_no"])

    DATA['GPA'] = (DATA['G1']+DATA['G2']+DATA['G3'])/3
    DATA = DATA.drop(['G1', 'G2', 'G3'], axis = 1)

    DATA = DATA.drop('school_GP', axis = 1)

    # ----------------------------------- Saving data ---------------------------------------
    DATA.to_csv('../data/processed_data/student-mat.csv')

if __name__ == "__main__":
    main()