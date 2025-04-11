#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <stdexcept>

// Constructors
template<typename T>
Matrix<T>::Matrix() : size(0) {}

template<typename T>
Matrix<T>::Matrix(int n) : size(n) {
    data.resize(n, std::vector<T>(n));
}

// Load a matrix from a file stream
template<typename T>
void Matrix<T>::loadFromFile(std::ifstream& file) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> data[i][j];
}

// Print the matrix
template<typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << std::setw(8) << data[i][j];
        std::cout << std::endl;
    }
}

// Add two matrices
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    Matrix<T> result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// Multiply two matrices
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    Matrix<T> result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
        }
    return result;
}

// Diagonal sum
template<typename T>
T Matrix<T>::diagonalSum() const {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i][i]; // main diagonal
        sum += data[i][size - 1 - i]; // secondary diagonal
    }
    return sum;
}

// Swap rows
template<typename T>
void Matrix<T>::swapRows(int row1, int row2) {
    if (row1 >= 0 && row2 >= 0 && row1 < size && row2 < size) {
        std::swap(data[row1], data[row2]);
    } else {
        std::cerr << "Error: Invalid row indices (" << row1 << ", " << row2 << ").\n";
    }
}


// Swap columns
template<typename T>
void Matrix<T>::swapCols(int col1, int col2) {
    if (col1 >= 0 && col2 >= 0 && col1 < size && col2 < size) {
        for (int i = 0; i < size; ++i)
            std::swap(data[i][col1], data[i][col2]);
    } else {
        std::cerr << "Error: Invalid column indices (" << col1 << ", " << col2 << ").\n";
    }
}


// Update element
template<typename T>
void Matrix<T>::updateElement(int row, int col, T value) {
    if (row >= 0 && col >= 0 && row < size && col < size) {
        data[row][col] = value;
    } else {
        std::cerr << "Error: Invalid indices (" << row << ", " << col << ") for update.\n";
    }
}


#endif
