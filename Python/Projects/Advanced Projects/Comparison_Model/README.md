<h1>Comparison of Models</h1>

<h3>Overview</h3>

This project aims to compare the performance of different machine learning models in predicting student performance based on a dataset containing various attributes related to students' backgrounds and academic performance. The models under comparison include linear regression, neural network, and decision tree.

<h3>Project Structure</h3>

```
.
├── data
│   ├── processed_data
|   |      └── student-mat.csv
|   └── raw_data
|          ├── student.txt
|          └── student-mat.csv        # Dataset file
├── notebooks
│   ├── preprocessing.ipynb             # Jupyter file to Preprocesses Data
│   └── model_training.ipynb            # Jupyter file to train models
├── models
│   ├── Tree.pkl         # Trained decision tree model
│   ├── Regression.pkl   # Trained linear regression model
│   └── Neural.keras     # Trained neural network model
├── src
│   ├── preprocessing.py             # Script to Preprocesses Data
│   └── model_training.py            # Script to train models
├── README.md                        # Project README
└── requirements.txt                 # Project dependencies
```

<h5>Installation</h5>

To install the necessary dependencies, run:
```bash
pip install -r requirements.txt
```

