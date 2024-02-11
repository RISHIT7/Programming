#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void print_mat(vector<vector<double>> result)
{
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}
// --------------------------------------------------------------- LINEAR_REGRESSOR ----------------------------------------------------------------------
bool inverseMatrix(const vector<std::vector<double>> &matrix, vector<std::vector<double>> &result)
{
    int n = matrix.size();
    if (n == 0 || matrix[0].size() != n)
    {
        std::cerr << "Invalid matrix dimensions." << std::endl;
        return false;
    }

    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i)
    {
        augmentedMatrix[i][i + n] = 1.0;
        for (int j = 0; j < n; ++j)
        {
            augmentedMatrix[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (augmentedMatrix[i][i] == 0.0)
        {
            std::cerr << "Matrix is not invertible." << std::endl;
            return false;
        }

        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                double ratio = augmentedMatrix[j][i] / augmentedMatrix[i][i];
                for (int k = 0; k < 2 * n; ++k)
                {
                    augmentedMatrix[j][k] -= ratio * augmentedMatrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        double pivot = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j)
        {
            augmentedMatrix[i][j] /= pivot;
        }
    }

    result.resize(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return true;
}
vector<vector<double>> crossMultiply_1(const vector<vector<double>> matrix1, const vector<vector<double>> matrix2)
{
    vector<double> result(matrix1.size(), 0);
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            result[i] += matrix1[i][j] * matrix2[0][j];
        }
    }

    return {result};
}

vector<vector<double>> crossMultiply(const vector<vector<double>> matrix1, const vector<vector<double>> matrix2)
{
    vector<double> tempb(matrix2[0].size(), 0);
    vector<vector<double>> result(matrix1.size(), tempb);
    
    for (int i = 0; i < matrix1.size(); ++i)
    {
        for (int j = 0; j < matrix1.size(); ++j)
        {
            for (int k = 0; k < matrix1[0].size(); k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

vector<vector<double>> transposeMatrix(vector<vector<double>> mat)
{
    vector<double> tempa(mat.size(), 0);
    vector<vector<double>> x_transpose(mat[0].size(), tempa);

    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            x_transpose[j][i] = mat[i][j];
        }
    }
    return x_transpose;
}

// -------------------------------------------------------------------------- PARAMS -------------------------------------------------------------------
vector<vector<double>> solve(vector<vector<double>> x_matrix, vector<vector<double>> y_matrix)
{

    // Calculate the transpose
    vector<vector<double>> x_transpose = transposeMatrix(x_matrix);
    // XTX
    vector<vector<double>> x_transpose_x = crossMultiply(x_transpose, x_matrix);
    // XTy
    vector<vector<double>> x_transpose_y = crossMultiply_1(x_transpose, y_matrix);
    // (XTX)^-1
    vector<vector<double>> result;
    inverseMatrix(x_transpose_x, result);
    // (XTX)^-1 * (XTy)
    vector<vector<double>> params = crossMultiply_1(result, x_transpose_y);

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
    vector<pair<string, double>> data;
    vector<vector<double>> x_matrix;
    vector<vector<double>> y_matrix;

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
    vector<double> open;
    for (int i = 1; i < x_matrix.size(); i++)
    {
        open.push_back(x_matrix[i][1]);
    }
    x_matrix.pop_back();
    for (int i = 0; i < x_matrix.size(); i++)
    {
        x_matrix[i][6] = open[i];
    }

    // finding the params
    vector<vector<double>> params = solve(x_matrix, y_matrix);

    return 0;
}
