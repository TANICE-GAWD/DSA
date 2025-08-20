#include <iostream>
using namespace std;

struct Element {
  int row, col, val;
};

struct Sparse {
  int rows, cols, num;
  Element *ele;
};

Sparse multiply(Sparse a, Sparse b) {
  Sparse c;
  c.rows = a.rows;
  c.cols = b.cols;
  c.ele = new Element[a.num * b.num];
  int k = 0;
  for (int i = 0; i < a.num; i++)
    for (int j = 0; j < b.num; j++)
      if (a.ele[i].col == b.ele[j].row) {
        int r = a.ele[i].row, co = b.ele[j].col,
            v = a.ele[i].val * b.ele[j].val;
        int found = 0;
        for (int m = 0; m < k; m++) {
          if (c.ele[m].row == r && c.ele[m].col == co) {
            c.ele[m].val += v;
            found = 1;
            break;
          }
        }
        if (!found)
          c.ele[k++] = {r, co, v};
      }
  c.num = k;
  return c;
}

int main() {
  Sparse a, b;
  a.rows = 2;
  a.cols = 2;
  a.num = 2;
  a.ele = new Element[2]{{0, 0, 2}, {1, 1, 3}};
  b.rows = 2;
  b.cols = 2;
  b.num = 2;
  b.ele = new Element[2]{{0, 0, 4}, {1, 1, 5}};
  Sparse c = multiply(a, b);
  for (int i = 0; i < c.num; i++)
    cout << c.ele[i].row << " " << c.ele[i].col << " " << c.ele[i].val << endl;
}
