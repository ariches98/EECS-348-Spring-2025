#include <iostream>
#include "matrix.h"

// menu to show options
void showMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Swap rows\n";
    std::cout << "2. Swap columns\n";
    std::cout << "3. Update element\n";
    std::cout << "4. Show matrix A\n";
    std::cout << "5. Show matrix B\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}


Matrix& selectMatrix(Matrix& A, Matrix& B) {
    char choice;
    std::cout << "Modify Matrix A or B? (A/B): ";
    std::cin >> choice;
    return (choice == 'B' || choice == 'b') ? B : A;
}

int main() {
    Matrix A, B;
    int N;

    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    readMatrixFromFile(filename, A, B, N);

    std::cout << "\nMatrix A:\n";
    printMatrix(A);
    std::cout << "\nMatrix B:\n";
    printMatrix(B);

    std::cout << "\nMatrix A + B:\n";
    printMatrix(addMatrices(A, B));

    std::cout << "\nMatrix A * B:\n";
    printMatrix(multiplyMatrices(A, B));

    std::cout << "\nMain diagonal sum of A: " << sumMainDiagonal(A) << "\n";
    std::cout << "Secondary diagonal sum of A: " << sumSecondaryDiagonal(A) << "\n";

    std::cout << "\nMain diagonal sum of B: " << sumMainDiagonal(B) << "\n";
    std::cout << "Secondary diagonal sum of B: " << sumSecondaryDiagonal(B) << "\n";

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Matrix& target = selectMatrix(A, B);
            int r1, r2;
            std::cout << "Enter two row indices to swap (separated by space): ";
            if (std::cin >> r1 >> r2) {
                swapRows(target, r1, r2);
                std::cout << "Matrix after row swap:\n";
                printMatrix(target);
            }
            else {
                std::cerr << "Invalid input. Please enter two integers.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        }


        case 2: {
            Matrix& target = selectMatrix(A, B);
            int c1, c2;
            std::cout << "Enter two column indices to swap (separated by space): ";
            if (std::cin >> c1 >> c2) {
                swapColumns(target, c1, c2);
                std::cout << "Matrix after column swap:\n";
                printMatrix(target);
            }
            else {
                std::cerr << "Invalid input. Please enter two integers.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        }


        case 3: {
            Matrix& target = selectMatrix(A, B);
            int row, col, val;
            std::cout << "Enter row index, column index, and new value: ";
            if (std::cin >> row >> col >> val) {
                updateElement(target, row, col, val);
                std::cout << "Matrix after update:\n";
                printMatrix(target);
            }
            else {
                std::cerr << "Invalid input. Please enter three integers.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        }


        case 4:
            std::cout << "Matrix A:\n";
            printMatrix(A);
            break;
        case 5:
            std::cout << "Matrix B:\n";
            printMatrix(B);
            break;
        case 6:
            std::cout << "Exiting.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
