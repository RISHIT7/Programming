#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int N = 8;

void print(vector<vector<double>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<vector<double>> gaussianElimination(vector<vector<double>> A)
{
    vector<double> temp(N, 0);
    vector<vector<double>> I(N, temp);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            I[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    // Forward elimination
    for (int i = 0; i < N; ++i)
    {
        double pivot = A[i][i];
        if (pivot == 0)
        {
            cout << "Matrix not invertible" << endl;
            return {{}};
        }

        // Normalize the pivot row
        for (int j = 0; j < N; ++j)
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

        // Eliminate other rows
        for (int k = 0; k < N; ++k)
        {
            if (k != i)
            {
                double factor = A[k][i];
                for (int j = 0; j < N; ++j)
                {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    return I;
}

int main()
{
    vector<vector<double>> matrix = {
        {1, 4, 5, 6, 7, 8, 9, 6},
        {15, 5, 6, 7, 8, 9, 6, 5},
        {12, 7, 8, 6, 45, 7, 7, 6},
        {435, 67, 8, 7, 6, 7, 8, 9},
        {12, 4, 6, 7, 8, 8, 66, 345},
        {234, 8, 6, 6, 7, 8, 8, 66},
        {123, 7, 8, 345, 76, 7, 8, 8},
        {4, 5, 3, 6, 7, 2, 1, 3}};

    cout << "Original Matrix:" << endl;
    print(matrix);

    // Apply Gaussian elimination
    vector<vector<double>> identity = gaussianElimination(matrix);

    cout << "\nInverse Matrix:" << endl;
    print(identity);

    return 0;
}