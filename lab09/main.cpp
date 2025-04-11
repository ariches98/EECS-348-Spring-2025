#include "Matrix.hpp"
#include <fstream>
#include <memory>
#include <limits>


int main() {
    std::string filename;
    std::cout << "Enter the input file name (e.g., matrix.txt): ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file.\n";
        return 1;
    }

    int size;
    int typeFlag;
    file >> size >> typeFlag;

    std::cout << "\nMatrix size: " << size << "x" << size << "\n";
    std::cout << "Matrix type: " << (typeFlag == 0 ? "int" : "double") << "\n\n";

    if (typeFlag == 0) {
        Matrix<int> A(size), B(size);
        A.loadFromFile(file);
        B.loadFromFile(file);

        std::cout << "Matrix A:\n";
        A.print();

        std::cout << "\nMatrix B:\n";
        B.print();

        std::cout << "\nA + B:\n";
        Matrix<int> sum = A + B;
        sum.print();

        std::cout << "\nA * B:\n";
        Matrix<int> product = A * B;
        product.print();

        std::cout << "\nDiagonal Sum of A: " << A.diagonalSum() << "\n";

        // Menu loop for editing matrices (int)
        char choice;
        do {
            std::cout << "\nMatrix Editing Menu (int version):\n";
            std::cout << "1. Swap rows\n";
            std::cout << "2. Swap columns\n";
            std::cout << "3. Update an element\n";
            std::cout << "4. Print matrix A\n";
            std::cout << "5. Print matrix B\n";
            std::cout << "0. Exit\n";
            std::cout << "Select an option: ";
            std::cin >> choice;

            int matrixChoice = -1;
            if (choice >= '1' && choice <= '3') {
                while (true) {
                    std::cout << "Edit Matrix A (0) or B (1)? ";
                    std::cin >> matrixChoice;

                    if (std::cin.fail() || (matrixChoice != 0 && matrixChoice != 1)) {
                        std::cin.clear(); // clear failbit
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cerr << "Invalid input. Please enter 0 for A or 1 for B.\n";
                    }
                    else {
                        break;
                    }
                }
            }


            int r1, r2, c1, c2;
            int row, col;
            int newVal;

            switch (choice) {
            case '1':
                std::cout << "Enter row1 and row2 to swap: ";
                std::cin >> r1 >> r2;
                if (matrixChoice == 0) A.swapRows(r1, r2);
                else B.swapRows(r1, r2);
                break;
            case '2':
                std::cout << "Enter col1 and col2 to swap: ";
                std::cin >> c1 >> c2;
                if (matrixChoice == 0) A.swapCols(c1, c2);
                else B.swapCols(c1, c2);
                break;
            case '3':
                while (true) {
                    std::cout << "Enter row, col, and new value: ";
                    if (std::cin >> row >> col >> newVal)
                        break;

                    std::cin.clear(); // clear fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid input. Please enter three values.\n";
                }

            case '4':
                A.print();
                break;
            case '5':
                B.print();
                break;
            }
        } while (choice != '0');

    }
    else {
        Matrix<double> A(size), B(size);
        A.loadFromFile(file);
        B.loadFromFile(file);

        std::cout << "Matrix A:\n";
        A.print();

        std::cout << "\nMatrix B:\n";
        B.print();

        std::cout << "\nA + B:\n";
        Matrix<double> sum = A + B;
        sum.print();

        std::cout << "\nA * B:\n";
        Matrix<double> product = A * B;
        product.print();

        std::cout << "\nDiagonal Sum of A: " << A.diagonalSum() << "\n";

        // Menu loop for editing matrices (double)
        char choice;
        do {
            std::cout << "\nMatrix Editing Menu (double version):\n";
            std::cout << "1. Swap rows\n";
            std::cout << "2. Swap columns\n";
            std::cout << "3. Update an element\n";
            std::cout << "4. Print matrix A\n";
            std::cout << "5. Print matrix B\n";
            std::cout << "0. Exit\n";
            std::cout << "Select an option: ";
            std::cin >> choice;

            int matrixChoice = -1;
            if (choice >= '1' && choice <= '3') {
                while (true) {
                    std::cout << "Edit Matrix A (0) or B (1)? ";
                    std::cin >> matrixChoice;

                    if (std::cin.fail() || (matrixChoice != 0 && matrixChoice != 1)) {
                        std::cin.clear(); // clear failbit
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                        std::cerr << "Invalid input. Please enter 0 for A or 1 for B.\n";
                    }
                    else {
                        break;
                    }
                }
            }


            int r1, r2, c1, c2;
            int row, col;
            double newVal;

            switch (choice) {
            case '1':
                std::cout << "Enter row1 and row2 to swap: ";
                std::cin >> r1 >> r2;
                if (matrixChoice == 0) A.swapRows(r1, r2);
                else B.swapRows(r1, r2);
                break;
            case '2':
                std::cout << "Enter col1 and col2 to swap: ";
                std::cin >> c1 >> c2;
                if (matrixChoice == 0) A.swapCols(c1, c2);
                else B.swapCols(c1, c2);
                break;
            case '3':
                while (true) {
                    std::cout << "Enter row, col, and new value: ";
                    if (std::cin >> row >> col >> newVal)
                        break;

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid input. Please enter three values.\n";
                }

            case '4':
                A.print();
                break;
            case '5':
                B.print();
                break;
            }
        } while (choice != '0');
    }

    return 0;
}
