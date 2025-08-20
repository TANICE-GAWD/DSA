#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
  for (int i = 0; i <= size; i++) {
    for (int j = 0; j <= size - i; j++) {
      if (arr[j] > arr[j + 1]) {
        arr[j] ^= arr[j + 1] ^= arr[j] ^= arr[j + 1];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};

  bubbleSort(arr, 6);

  for (int i : arr) {
    cout << i << " ";
  }
  return 0;
}
