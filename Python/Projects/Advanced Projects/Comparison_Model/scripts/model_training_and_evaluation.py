import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from sklearn.linear_model import Ridge
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.regularizers import L2
from xgboost import XGBRegressor
import seaborn as sns

def regression_train(x_train, y_train):
    model = Ridge(alpha = 10)
    model.fit(x_train, y_train)
    
    return model
    
def neuralNetwork_train(x_train, y_train):
    lambda_ = 0.066
    model = Sequential(
        [
            Dense(32, activation = 'relu', kernel_regularizer=L2(lambda_)),
            Dense(16, activation = 'relu', kernel_regularizer=L2(lambda_)),
            Dense(8, activation = 'relu', kernel_regularizer=L2(lambda_)),
            Dense(4, activation = 'relu', kernel_regularizer=L2(lambda_)),
            Dense(12, activation = 'relu', kernel_regularizer=L2(lambda_)),
            Dense(1, activation = 'linear', kernel_regularizer=L2(lambda_))
        ],
        name='model_fin'
    )
    model.compile(
        loss = 'mse',
        optimizer = Adam(learning_rate=0.1),
    )
    model.fit(x_train, y_train,
            epochs = 300,
            verbose = 0)
    
    return model

def XGB_train(x_train, y_train, x_test, y_test):
    lambda_ = 0.001*2*31
    model = XGBRegressor(n_estimators = 500, learning_rate = 0.1, verbosity = 1, random_state = 0, gamma = lambda_)
    model.fit(x_train, y_train, eval_set=[(x_test, y_test)], early_stopping_rounds=10)

    return model

def load_data():
    df = pd.read_csv('../data/processed_data/student-mat.csv')
    y = df['GPA']
    x = df.drop(['GPA'], axis = 1).iloc[:, 1:]

    return train_test_split(x, y, test_size=0.3, random_state=42)

def compare_errors(model1, model2, model3, x_test, y_test):
    result = {}
    result['Regression'] = mean_squared_error(y_test, model1.predict(x_test))
    result['NN'] = mean_squared_error(y_test, model2.predict(x_test))
    result['XGB'] = mean_squared_error(y_test, model3.predict(x_test))
    
    return result

def main():
    x_train, x_test, y_train, y_test = load_data()
    
    # Training Regression Model
    regression_model = regression_train(x_train, y_train)
    
    # Training Neural Network Model
    NN_Model = neuralNetwork_train(x_train, y_train)
    
    # Training Descision Tree Model (XGB)
    XGB_Model = XGB_train(x_train, y_train, x_test, y_test)

    # Comparing the output
    result = compare_errors(regression_model, NN_Model, XGB_Model, x_test, y_test)
    data = {'Model': list(result.keys()), 'Error': list(result.values())}
    df = pd.DataFrame(data)
    sns.barplot(df, x = 'Model', y = 'Error')