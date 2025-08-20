#include <iostream>
using namespace std;

class TriDiagonal {
  int n;
  int *A;

public:
  TriDiagonal(int size) {
    n = size;
    A = new int[3 * n - 2];
  }
  void set(int i, int j, int x) {
    if (i - j == 1)
      A[i - 2] = x;
    else if (i == j)
      A[n - 1 + i - 1] = x;
    else if (j - i == 1)
      A[2 * n - 1 + i - 1] = x;
  }
  int get(int i, int j) {
    if (i - j == 1)
      return A[i - 2];
    else if (i == j)
      return A[n - 1 + i - 1];
    else if (j - i == 1)
      return A[2 * n - 1 + i - 1];
    return 0;
  }
};

int main() {
  TriDiagonal t(4);
  t.set(1, 1, 2);
  t.set(2, 2, 3);
  t.set(3, 3, 4);
  cout << t.get(1, 1) << " " << t.get(2, 2) << " " << t.get(3, 3) << endl;
}
