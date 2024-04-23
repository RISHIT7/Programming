# Comparison of Models

Welcome to the Comparison of Models project! This project aims to evaluate the performance of various machine learning models in predicting student performance based on a dataset containing attributes related to students' backgrounds and academic outcomes. The models under comparison include linear regression, neural networks, and decision trees.

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Models](#models)
- [Results](#results)
- [License](#license)

## Overview
The goal of this project is to assess the predictive capabilities of different machine learning models using a student performance dataset. The dataset contains various features related to students' backgrounds and academic performance. By comparing different models, the project aims to identify the best approach for predicting student outcomes.

## Project Structure
The project is organized into the following directories and files:

```
.
├── data
│   ├── processed_data
|   |      └── student-mat.csv
|   └── raw_data
|          ├── student.txt
|          └── student-mat.csv        # Dataset file
├── notebooks
│   ├── preprocessing.ipynb           # Jupyter file for data preprocessing
│   └── model_training.ipynb          # Jupyter file for model training
├── models
│   ├── Tree.pkl         # Trained decision tree model
│   ├── Regression.pkl   # Trained linear regression model
│   └── Neural.keras     # Trained neural network model
├── src
│   ├── preprocessing.py             # Script for data preprocessing
│   └── model_training.py            # Script for model training
├── README.md                        # Project README
└── requirements.txt                 # Project dependencies
```

- **data**: Contains raw and processed data for the project.
- **notebooks**: Contains Jupyter notebooks for data preprocessing and model training.
- **models**: Contains the trained models (decision tree, linear regression, and neural network).
- **src**: Contains Python scripts for data preprocessing and model training.
- **README.md**: This file provides an overview and guide to the project.
- **requirements.txt**: Lists the Python packages required for the project.

## Installation
To install the required dependencies, run the following command in your terminal:

```bash
pip install -r requirements.txt
```

## Usage
1. **Preprocess Data**: Start by running the `preprocessing.ipynb` notebook or the `preprocessing.py` script to preprocess the raw data.

2. **Train Models**: Run the `model_training.ipynb` notebook or the `model_training.py` script to train the different models on the processed data.

3. **Compare Models**: After training the models, compare their performance using metrics such as accuracy, precision, recall, or F1 score.

4. **Evaluate Results**: Review the results to determine which model performs best for predicting student performance.

## Models
- **Linear Regression**: A classic model for predicting continuous outcomes.
- **Decision Tree**: A decision-making model that segments data into branches based on features.
- **Neural Network**: A deep learning model capable of handling complex data patterns.

## Results
The project includes results obtained from training and evaluating each model. These results include performance metrics such as accuracy, precision, recall, and F1 score. You can find more detailed information about the results in the respective notebooks.

## License
This project is licensed under the [MIT License](LICENSE). Please see the LICENSE file for more details.
