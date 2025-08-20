#include <iostream>
using namespace std;

class LowerTriangular {
  int n;
  int *A;

public:
  LowerTriangular(int size) {
    n = size;
    A = new int[n * (n + 1) / 2];
  }
  void set(int i, int j, int x) {
    if (i >= j)
      A[i * (i - 1) / 2 + (j - 1)] = x;
  }
  int get(int i, int j) { return (i >= j) ? A[i * (i - 1) / 2 + (j - 1)] : 0; }
};

int main() {
  LowerTriangular l(3);
  l.set(1, 1, 1);
  l.set(2, 1, 2);
  l.set(2, 2, 3);
  cout << l.get(2, 1) << " " << l.get(2, 2) << " " << l.get(1, 2) << endl;
}
