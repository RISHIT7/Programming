#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

// -------------------------------------------------------------------------- PARAMS -------------------------------------------------------------------
VectorXf normalEquation(const MatrixXf& X, const VectorXf& Y) {
    // Calculate the solution: beta = (X^T * X)^(-1) * X^T * Y
    VectorXf beta = (X.transpose() * X).inverse() * X.transpose() * Y;
    return beta;
}

MatrixXd vectorToMatrix(const vector<vector<double>>& input) {
    int rows = input.size();
    int cols = (rows > 0) ? input[0].size() : 0;

    MatrixXd result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = input[i][j];
        }
    }

    return result;
}

vector<vector<double>> matrixToVector(const MatrixXd& input) {
    int rows = input.rows();
    int cols = input.cols();

    vector<vector<double>> result(rows, vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = input(i, j);
        }
    }

    return result;
}
// -------------------------------------------------------------------------- MAIN ---------------------------------------------------------------------
int main(int argv, char *argc[])
{
    // system args
    string symbol{argc[1]};
    int x{stoi(argc[2])};
    int p{stoi(argc[3])};
    string train_start_date{argc[4]};
    string train_end_date{argc[5]};

    // data files initiation
    vector<pair<string, double>> data;
    vector<vector<double>> y_matrix;
    vector<vector<double>> x_matrix;

    // loading train data
    ifstream file("Stocks/" + symbol + "_train.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string first_line;
    getline(file, first_line);

    string line;
    while (getline(file, line))
    {
        // datas to be loaded
        string date, close, high, low, prevClose, vwap, noOfTrades, open;

        // loading
        stringstream ss(line);
        getline(ss, date, ',');
        getline(ss, close, ',');
        getline(ss, high, ',');
        getline(ss, low, ',');
        getline(ss, prevClose, ',');
        getline(ss, vwap, ',');
        getline(ss, noOfTrades, ',');
        getline(ss, open, '\n');
        y_matrix.push_back({stod(close)});
        x_matrix.push_back({stod(close), stod(open), stod(vwap), stod(low), stod(high), stod(noOfTrades), 0});
    }
    file.close();

    // adjusting the time according to the linear regression requirements
    y_matrix.erase(y_matrix.begin());
    vector<double> open = x_matrix[1];
    x_matrix.pop_back();
    for (int i = 0; i < x_matrix[0].size(); i++)
    {
        x_matrix[x_matrix.size() - 1][i] = open[i + 1];
    }

    // vector to matrix
    MatrixXd X = vectorToMatrix(x_matrix);
    MatrixXd Y = vectorToMatrix(y_matrix);

    // finding the params
    VectorXd params = normalEquation(X, Y);
    vector<vector<double>> params = matrixToVector(params);
    print_mat(params);
    return 0;
}
