#include <iostream>
#include <vector>

// Function to print a matrix
void printMatrix(const std::vector<std::vector<double>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (double element : row)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Function to calculate the cofactor of a matrix element
void getCofactor(const std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &temp, int p, int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    ++i;
                }
            }
        }
    }
}

// Function to calculate the determinant of a matrix
double determinant(const std::vector<std::vector<double>> &matrix, int n)
{
    if (n == 1)
    {
        return matrix[0][0];
    }

    double det = 0.0;
    std::vector<std::vector<double>> temp(n - 1, std::vector<double>(n - 1, 0.0));
    int sign = 1;

    for (int i = 0; i < n; ++i)
    {
        getCofactor(matrix, temp, 0, i, n);
        det += sign * matrix[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

// Function to calculate the adjoint of a matrix
void adjoint(const std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &adj)
{
    int n = matrix.size();
    if (n == 0 || matrix[0].size() != n)
    {
        std::cerr << "Invalid matrix dimensions." << std::endl;
        return;
    }

    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    std::vector<std::vector<double>> temp(n - 1, std::vector<double>(n - 1, 0.0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            getCofactor(matrix, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, n - 1));
        }
    }
}

// Function to calculate the inverse of a matrix
void inverse(const std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &inv)
{
    int n = matrix.size();
    if (n == 0 || matrix[0].size() != n)
    {
        std::cerr << "Invalid matrix dimensions." << std::endl;
        return;
    }

    double det = determinant(matrix, n);
    if (det == 0)
    {
        std::cerr << "Inverse does not exist, determinant is zero." << std::endl;
        return;
    }

    std::vector<std::vector<double>> adj(n, std::vector<double>(n, 0.0));
    adjoint(matrix, adj);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inv[i][j] = adj[i][j] / det;
        }
    }
}

int main()
{
    // Example usage
    std::vector<std::vector<double>> matrix = {
        {3, 12, 273, 18},
        {12, 66, 1479, 90},
        {273, 1479, 35937, 2025},
        {18, 90, 2025, 126},
    };

    int n = matrix.size();

    std::cout << "Matrix:" << std::endl;
    printMatrix(matrix);

    std::vector<std::vector<double>> inv(n, std::vector<double>(n, 0.0));
    inverse(matrix, inv);

    std::cout << "\nInverse Matrix:" << std::endl;
    printMatrix(inv);

    return 0;
}
