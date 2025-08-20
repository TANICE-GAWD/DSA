#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int arr[] = {1, 2, 2, 3, 4, 1, 5}, n = 7;
  unordered_set<int> s(arr, arr + n);
  cout << s.size() << endl;
}
