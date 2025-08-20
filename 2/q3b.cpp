#include <iostream>
using namespace std;

int binarySearch(int arr[], int n) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] < mid + 1)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
  cout << "Missing number is " << binarySearch(arr, 10);
  return 0;
}
