#include <iostream>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

const int R1_MULT = 2, C1_MULT = 3;
const int R2_MULT = 3, C2_MULT = 2;

void multiplyMatrices(int mat1[][C1_MULT], int mat2[][C2_MULT], int result[][C2_MULT]) {
    
    for (int i = 0; i < R1_MULT; i++) {
        for (int j = 0; j < C2_MULT; j++) {
            result[i][j] = 0;
        }
    }

    
    for (int i = 0; i < R1_MULT; i++) {        
        for (int j = 0; j < C2_MULT; j++) {    
            for (int k = 0; k < C1_MULT; k++) { 
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}




const int ROWS_TRANS = 2, COLS_TRANS = 4;
void findTranspose(int matrix[][COLS_TRANS], int transpose[][ROWS_TRANS]) {
    for (int i = 0; i < ROWS_TRANS; i++) {
        for (int j = 0; j < COLS_TRANS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    
    
    
    std::cout << "## a. Reversing an Array ##\n";
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    reverseArray(arr, size);

    std::cout << "Reversed array: ";
    printArray(arr, size);
    std::cout << "\n----------------------------------------\n\n";


    
    
    
    std::cout << "## b. Multiplying two Matrices ##\n";
    
    
    int mat1[R1_MULT][C1_MULT] = {
        {1, 1, 1},
        {2, 2, 2}
    };
    int mat2[R2_MULT][C2_MULT] = {
        {3, 3},
        {4, 4},
        {5, 5}
    };
    int result[R1_MULT][C2_MULT];

    multiplyMatrices(mat1, mat2, result);
    
    std::cout << "Matrix 1 (" << R1_MULT << "x" << C1_MULT << "):\n";
    for (int i = 0; i < R1_MULT; i++) {
        for (int j = 0; j < C1_MULT; j++) { std::cout << mat1[i][j] << " "; }
        std::cout << std::endl;
    }
    
    std::cout << "\nMatrix 2 (" << R2_MULT << "x" << C2_MULT << "):\n";
    for (int i = 0; i < R2_MULT; i++) {
        for (int j = 0; j < C2_MULT; j++) { std::cout << mat2[i][j] << " "; }
        std::cout << std::endl;
    }
    
    std::cout << "\nResultant Matrix (" << R1_MULT << "x" << C2_MULT << "):\n";
    for (int i = 0; i < R1_MULT; i++) {
        for (int j = 0; j < C2_MULT; j++) { std::cout << result[i][j] << " "; }
        std::cout << std::endl;
    }
    std::cout << "\n----------------------------------------\n\n";
    

    
    
    
    std::cout << "## c. Finding the Transpose of a Matrix ##\n";
    int matrix_to_transpose[ROWS_TRANS][COLS_TRANS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    int transpose_result[COLS_TRANS][ROWS_TRANS];

    findTranspose(matrix_to_transpose, transpose_result);

    std::cout << "Original Matrix (" << ROWS_TRANS << "x" << COLS_TRANS << "):\n";
    for (int i = 0; i < ROWS_TRANS; i++) {
        for (int j = 0; j < COLS_TRANS; j++) { std::cout << matrix_to_transpose[i][j] << "\t"; }
        std::cout << std::endl;
    }

    std::cout << "\nTransposed Matrix (" << COLS_TRANS << "x" << ROWS_TRANS << "):\n";
    for (int i = 0; i < COLS_TRANS; i++) {
        for (int j = 0; j < ROWS_TRANS; j++) { std::cout << transpose_result[i][j] << "\t"; }
        std::cout << std::endl;
    }
    
    return 0;
}