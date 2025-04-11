#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int size;

public:
    Matrix(); // default constructor
    Matrix(int n); // size constructor

    void loadFromFile(std::ifstream& file); // reads one matrix
    void print() const;

    // Operator Overloads
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;

    // Diagonal sum
    T diagonalSum() const;

    // Row/column operations
    void swapRows(int row1, int row2);
    void swapCols(int col1, int col2);
    void updateElement(int row, int col, T value);
};

#include "Matrix.tpp" // Template implementation

#endif
