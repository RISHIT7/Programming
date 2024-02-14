#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

void print(vector<vector<long double>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

// ------------------------------------------------- DETERMINANT ---------------------------------------------------------
long double get_determinant(vector<vector<long double>> matrix)
{
    int size = matrix.size();

    // Base case: if the matrix is 1x1, return its only element
    if (size == 1)
    {
        return matrix[0][0];
    }

    // Initialize determinant
    long double det = 0;

    // Recursive expansion along the first row
    for (int col = 0; col < size; col++)
    {
        // Calculate the minor matrix (matrix without the current row and column)
        vector<vector<long double>> minorMatrix(size - 1, vector<long double>(size - 1, 0));
        for (int i = 1; i < size; i++)
        {
            for (int j = 0, k = 0; j < size; j++)
            {
                if (j != col)
                {
                    minorMatrix[i - 1][k++] = matrix[i][j];
                }
            }
        }

        // Add or subtract the determinant of the minor matrix multiplied by the current element
        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * get_determinant(minorMatrix);
    }

    return det;
}

// --------------------------------------------------------------- LINEAR_REGRESSOR ----------------------------------------------------------------------
vector<vector<long double>> gaussianElimination(const vector<vector<long double>> mat)
{
    const int N = 8;
    vector<vector<long double>> I(N, vector<long double>(N, 0));
    vector<vector<long double>> A = mat;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            I[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    // print(mat);
    // cout << "-----------------" << endl;
    // print(I);
    // cout << "-----------------" << endl;
    // Forward elimination
    for (int i = 0; i < N; i++)
    {
        long double pivot = A[i][i];
        if (pivot == 0)
        {
            cout << "Matrix not invertible" << endl;
            return {{}};
        }


        // Eliminate other rows
        for (int k = 0; k < N; k++)
        {
            if (k != i)
            {
                long double factor = A[k][i]/pivot;
                for (int j = 0; j < N; j++)
                {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
        // Normalize the pivot row
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] != 0)
            {
                A[i][j] /= pivot;
            }
            if (I[i][j] != 0)
            {
                I[i][j] /= pivot;
            }
        }
        // print(A);
        // cout << "-----------------" << endl;
        // print(I);
        // cout << "-----------------" << endl;
    }
    return I;
}

vector<vector<long double>> crossMultiply_1(const vector<vector<long double>> matrix1, const vector<vector<long double>> matrix2)
{
    vector<long double> result(matrix1.size(), 0);
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            result[i] += matrix1[i][j] * matrix2[0][i];
        }
    }

    return {result};
}

vector<vector<long double>> crossMultiply(const vector<vector<long double>> matrix1, const vector<vector<long double>> matrix2)
{
    vector<long double> tempb(matrix2[0].size(), 0);
    vector<vector<long double>> result(matrix1.size(), tempb);

    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1.size(); j++)
        {
            for (int k = 0; k < matrix1[0].size(); k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

vector<vector<long double>> transposeMatrix(vector<vector<long double>> mat)
{
    vector<long double> tempa(mat.size(), 0);
    vector<vector<long double>> x_transpose(mat[0].size(), tempa);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            x_transpose[j][i] = mat[i][j];
        }
    }
    return x_transpose;
}

// -------------------------------------------------------------------------- PARAMS -------------------------------------------------------------------
vector<vector<long double>> solve(vector<vector<long double>> x_matrix, vector<vector<long double>> y_matrix)
{

    // Calculate the transpose
    vector<vector<long double>> x_transpose = transposeMatrix(x_matrix);
    // XTX
    vector<vector<long double>> x_transpose_x = crossMultiply(x_transpose, x_matrix);
    // XTy
    vector<vector<long double>> x_transpose_y = crossMultiply_1(x_transpose, y_matrix);
    // (XTX)^-1
    vector<vector<long double>> inverse;
    inverse = gaussianElimination(x_transpose_x);
    // (XTX)^-1 * (XTy)

    vector<vector<long double>> temp = crossMultiply(inverse, x_transpose_x);

    vector<vector<long double>> params = crossMultiply_1(inverse, x_transpose_y);
    return params;
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
    vector<pair<string, vector<long double>>> data;
    vector<vector<long double>> x_matrix;
    vector<vector<long double>> y_matrix;

    // loading train data
    ifstream file(symbol + "_train.csv");
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
        x_matrix.push_back({1.0, stod(close), stod(open), stod(vwap), stod(low), stod(high), stod(noOfTrades), 0});
    }
    file.close();

    // adjusting the time according to the linear regression requirements
    y_matrix.erase(y_matrix.begin());
    vector<long double> open;
    for (int i = 1; i < x_matrix.size(); i++)
    {
        open.push_back(x_matrix[i][2]);
    }
    x_matrix.pop_back();
    for (int i = 0; i < x_matrix.size(); i++)
    {
        x_matrix[i][7] = open[i];
    }
    // finding the params
    vector<vector<long double>> params = solve(x_matrix, y_matrix);
    print(y_matrix);
    // finally getting to the buying and selling part
    // loading test data
    ifstream file1(symbol + ".csv");
    if (!file1.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    getline(file1, first_line);

    while (getline(file1, line))
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
        data.push_back({date, {stod(close), stod(open), stod(vwap), stod(low), stod(high), stod(noOfTrades)}});
    }
    file1.close();

    ofstream cash_file("results/daily_cashflow.csv");
    ofstream order_file("results/order_statistics.csv");
    ofstream final_file("results/final_pnl.txt");

    cash_file << "Date,Cashflow\n";
    order_file << "Date,Order_dir,Quantity,Price\n";

    long unsigned int len{data.size()};
    long double predicted_close{}, cashflow{};
    int stocks{};

    for (int i = 1; i < len; i++)
    {
        // naming data for convenience
        long double prev_close = data[i - 1].second[0];
        long double prev_open = data[i - 1].second[1];
        long double prev_vwap = data[i - 1].second[2];
        long double prev_low = data[i - 1].second[3];
        long double prev_high = data[i - 1].second[4];
        long double prev_noOfTrades = data[i - 1].second[5];
        long double open = data[i].second[1];
        long double close = data[i].second[0];

        // prediction
        predicted_close = params[0][0] + params[0][1] * prev_close + params[0][2] * prev_open + params[0][3] * prev_vwap + params[0][4] * prev_low + params[0][5] * prev_high + params[0][6] * prev_noOfTrades + params[0][7] * open;
        if ((predicted_close > close + (p / 100)) and stocks < x)
        {
            // buy
            stocks++;
            order_file << data[i].first << ",BUY,1," << data[i].second[0] << "\n";
            cashflow -= data[i].second[0];
        }
        else if ((predicted_close < close - (p / 100)) and stocks > -x)
        {
            // sell
            stocks--;
            order_file << data[i].first << ",SELL,1," << data[i].second[0] << "\n";
            cashflow += data[i].second[0];
        }

        // cash_file
        cash_file << data[i].first << "," << cashflow << "\n";
    }
    long double final_pnl{cashflow + (stocks * data[len - 1].second[0])};
    final_file << "Final pnl : " << final_pnl << "\n";

    cash_file.close();
    order_file.close();
    final_file.close();

    return 0;
}