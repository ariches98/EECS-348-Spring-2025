#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<int>>;

Matrix readMatrixFromFile(const std::string& filename, Matrix& matA, Matrix& matB, int& size); // read matrix from file
void printMatrix(const Matrix& mat); // print matrix

Matrix addMatrices(const Matrix& A, const Matrix& B); // add two matrices
Matrix multiplyMatrices(const Matrix& A, const Matrix& B); // multiply two matrices

int sumMainDiagonal(const Matrix& mat); // sum of main diagonal
int sumSecondaryDiagonal(const Matrix& mat); // sum of secondary diagonal

void swapRows(Matrix& mat, int row1, int row2); // swap two rows
void swapColumns(Matrix& mat, int col1, int col2); // swap two columns

void updateElement(Matrix& mat, int row, int col, int newVal); // update matrix element

#endif
