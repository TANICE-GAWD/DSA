#include <iostream>
const int ROWS = 3;
const int COLS = 4;
void printMatrix(int matrix[ROWS][COLS]) {
    std::cout << "The matrix is:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    
    int matrix[ROWS][COLS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    
    printMatrix(matrix);
    std::cout << "\n--- Calculating Sums ---\n" << std::endl;

    
    std::cout << "Sum of each row:" << std::endl;
    
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0;
        
        for (int j = 0; j < COLS; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Sum of Row " << i + 1 << ": " << rowSum << std::endl;
    }

    std::cout << "\n--------------------------\n" << std::endl;

    
    std::cout << "Sum of each column:" << std::endl;
    
    for (int j = 0; j < COLS; ++j) {
        int colSum = 0;
        
        for (int i = 0; i < ROWS; ++i) {
            colSum += matrix[i][j];
        }
        std::cout << "Sum of Column " << j + 1 << ": " << colSum << std::endl;
    }

    return 0;
}
