#include <iostream>
using namespace std;

class UpperTriangular {
  int n;
  int *A;

public:
  UpperTriangular(int size) {
    n = size;
    A = new int[n * (n + 1) / 2];
  }
  void set(int i, int j, int x) {
    if (i <= j)
      A[(i - 1) * n - (i - 2) * (i - 1) / 2 + (j - i)] = x;
  }
  int get(int i, int j) {
    return (i <= j) ? A[(i - 1) * n - (i - 2) * (i - 1) / 2 + (j - i)] : 0;
  }
};

int main() {
  UpperTriangular u(3);
  u.set(1, 1, 5);
  u.set(1, 2, 6);
  u.set(2, 3, 7);
  cout << u.get(1, 1) << " " << u.get(1, 2) << " " << u.get(2, 3) << endl;
}
