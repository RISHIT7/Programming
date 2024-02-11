#include "linear_regressor.h"
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

vector<vector<double>> crossMultiply(vector<vector<double>> matrix1, vector<vector<double>> matrix2)
{
#pragma omp parallel for
    if (matrix2.size() == 1)
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
#pragma omp parallel for
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
