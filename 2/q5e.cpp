#include <iostream>
using namespace std;

class Symmetric {
  int n;
  int *A;

public:
  Symmetric(int size) {
    n = size;
    A = new int[n * (n + 1) / 2];
  }
  void set(int i, int j, int x) {
    if (i >= j)
      A[i * (i - 1) / 2 + (j - 1)] = x;
    else
      A[j * (j - 1) / 2 + (i - 1)] = x;
  }
  int get(int i, int j) {
    if (i >= j)
      return A[i * (i - 1) / 2 + (j - 1)];
    return A[j * (j - 1) / 2 + (i - 1)];
  }
};

int main() {
  Symmetric s(3);
  s.set(1, 1, 4);
  s.set(2, 1, 5);
  s.set(3, 2, 6);
  cout << s.get(1, 1) << " " << s.get(2, 1) << " " << s.get(1, 2) << endl;
}
