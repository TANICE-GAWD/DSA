#include <iostream>
using namespace std;

int linear_search(int arr[]) {
  int size = sizeof(arr) / sizeof(arr[0]);
  int sum = (size * (size - 1)) / 2;

  for (int i = 0; i < size; i++) {
    sum -= i;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
  int missing = linear_search(arr);

  cout << "Missing number is: " << missing << endl;
  return 0;
}
