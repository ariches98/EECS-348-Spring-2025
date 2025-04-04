#include "matrix.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Matrix readMatrixFromFile(const std::string& filename, Matrix& matA, Matrix& matB, int& size) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        exit(1);
    }

    file >> size;
    matA.resize(size, std::vector<int>(size));
    matB.resize(size, std::vector<int>(size));

    // Matrix A
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> matA[i][j];

    // Matrix B
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> matB[i][j];

    return matA;
}

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (const auto& val : row) {
            std::cout << std::setw(4) << val;
        }
        std::cout << "\n";
    }
}

Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] + B[i][j];

    return result;
}

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += A[i][k] * B[k][j];

    return result;
}

int sumMainDiagonal(const Matrix& mat) {
    int sum = 0;
    for (int i = 0; i < mat.size(); ++i)
        sum += mat[i][i];
    return sum;
}

int sumSecondaryDiagonal(const Matrix& mat) {
    int sum = 0;
    int n = mat.size();
    for (int i = 0; i < n; ++i)
        sum += mat[i][n - i - 1];
    return sum;
}

void swapRows(Matrix& mat, int row1, int row2) {
    if (row1 >= 0 && row2 >= 0 && row1 < mat.size() && row2 < mat.size())
        std::swap(mat[row1], mat[row2]);
    else
        std::cerr << "Invalid row indices.\n";
}

void swapColumns(Matrix& mat, int col1, int col2) {
    if (col1 >= 0 && col2 >= 0 && col1 < mat.size() && col2 < mat.size()) {
        for (auto& row : mat)
            std::swap(row[col1], row[col2]);
    }
    else {
        std::cerr << "Invalid column indices.\n";
    }
}

void updateElement(Matrix& mat, int row, int col, int newVal) {
    if (row >= 0 && col >= 0 && row < mat.size() && col < mat.size()) {
        mat[row][col] = newVal;
    }
    else {
        std::cerr << "Invalid indices.\n";
    }
}
