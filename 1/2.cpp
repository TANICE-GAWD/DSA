#include <iostream>

int removeDuplicates(int arr[], int n) {
    
    if (n == 0 || n == 1) {
        return n;
    }

    
    
    int newSize = 1;

    
    for (int i = 1; i < n; i++) {
        bool isDuplicate = false;
        
        
        
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break; 
            }
        }

        
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++; 
        }
    }

    return newSize;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    int arr[] = {10, 20, 10, 30, 40, 40, 10, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    
    int newArraySize = removeDuplicates(arr, n);

    std::cout << "Array after removing duplicates: ";
    printArray(arr, newArraySize);

    return 0;
}