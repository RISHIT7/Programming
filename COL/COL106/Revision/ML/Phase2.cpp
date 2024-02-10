#include <iostream>
#include <vector>

// Function to perform Gaussian elimination to find the inverse of a matrix
bool inverseMatrix(const std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &result)
{
    int n = matrix.size();
    if (n == 0 || matrix[0].size() != n)
    {
        std::cerr << "Invalid matrix dimensions." << std::endl;
        return false;
    }

    // Augment the matrix with an identity matrix
    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i)
    {
        augmentedMatrix[i][i + n] = 1.0;
        for (int j = 0; j < n; ++j)
        {
            augmentedMatrix[i][j] = matrix[i][j];
        }
    }

    // Perform Gaussian elimination
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

    // Normalize the inverse matrix
    for (int i = 0; i < n; ++i)
    {
        double pivot = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j)
        {
            augmentedMatrix[i][j] /= pivot;
        }
    }

    // Extract the inverse matrix
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

int main()
{
    // Example usage
    std::vector<std::vector<double>> originalMatrix = {
        {3, 12, 273, 18},
        {12, 66, 1479, 90},
        {273, 1479, 35937, 2025},
        {18, 90, 2025, 126}};

    std::vector<std::vector<double>> inverse;
    if (inverseMatrix(originalMatrix, inverse))
    {
        std::cout << "Original Matrix:" << std::endl;
        for (const auto &row : originalMatrix)
        {
            for (double element : row)
            {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "\nInverse Matrix:" << std::endl;
        for (const auto &row : inverse)
        {
            for (double element : row)
            {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
