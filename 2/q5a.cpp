#include <iostream>
using namespace std;

class Diagonal {
  int n;
  int *A;

public:
  Diagonal(int size) {
    n = size;
    A = new int[n];
  }
  void set(int i, int j, int x) {
    if (i == j)
      A[i - 1] = x;
  }
  int get(int i, int j) { return (i == j) ? A[i - 1] : 0; }
};

int main() {
  Diagonal d(4);
  d.set(1, 1, 5);
  d.set(2, 2, 8);
  cout << d.get(1, 1) << " " << d.get(2, 2) << " " << d.get(1, 2) << endl;
}
