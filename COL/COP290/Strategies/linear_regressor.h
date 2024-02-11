#ifndef LINEAR_REGRESSOR_H
#define LINEAR_REGRESSOR_H

#include <vector>
using namespace std;

bool inverseMatrix(const vector<std::vector<double>> &matrix, vector<std::vector<double>> &result);

vector<vector<double>> crossMultiply(vector<vector<double>> matrix1, vector<vector<double>> matrix2);

vector<vector<double>> transposeMatrix(vector<vector<double>> mat);

void print_mat(vector<vector<double>> result);
#endif