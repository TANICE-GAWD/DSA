#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string arr[] = {"banana", "apple", "cherry", "date"};
  int n = 4;

  sort(arr, arr + n);

  cout << "Sorted strings:\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << "\n";
}
