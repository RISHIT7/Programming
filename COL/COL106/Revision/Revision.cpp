#include <iostream>
#include <cmath>
using namespace std;

const int N = 8;

void print(double matrix[N][N], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void gaussianElimination(double A[N][N], double I[N][N])
{
    // Forward elimination
    for (int i = 0; i < N; ++i)
    {
        double pivot = A[i][i];
        if (pivot == 0)
        {
            cout << "Matrix not invertible" << endl;
            return;
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
}

int main()
{
    double matrix[N][N] = {
        {4, 5, 6, 7, 8, 9, 6},
        {5, 6, 7, 8, 9, 6, 5},
        {7, 8, 6, 45, 7, 7, 6},
        {67, 8, 7, 6, 7, 8, 9},
        {4, 6, 7, 8, 8, 66, 345},
        {8, 6, 6, 7, 8, 8, 66},
        {7, 8, 345, 76, 7, 8, 8}
    };

    double identity[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            identity[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix, N, N);

    // Apply Gaussian elimination
    gaussianElimination(matrix, identity);

    std::cout << "\nInverse Matrix:" << std::endl;
    print(identity, N, N);

    return 0;
}