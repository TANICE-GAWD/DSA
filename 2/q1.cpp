#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  int key = 7;
  int idx = binarySearch(arr, n, key);

  if (idx != -1)
    cout << "Element found at index " << idx << "\n";
  else
    cout << "Element not found\n";
}
