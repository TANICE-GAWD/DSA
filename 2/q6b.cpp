#include <iostream>
using namespace std;

struct Element {
  int row, col, val;
};

struct Sparse {
  int rows, cols, num;
  Element *ele;
};

Sparse add(Sparse a, Sparse b) {
  Sparse c;
  c.rows = a.rows;
  c.cols = a.cols;
  c.ele = new Element[a.num + b.num];
  int i = 0, j = 0, k = 0;
  while (i < a.num && j < b.num) {
    if (a.ele[i].row < b.ele[j].row ||
        (a.ele[i].row == b.ele[j].row && a.ele[i].col < b.ele[j].col))
      c.ele[k++] = a.ele[i++];
    else if (b.ele[j].row < a.ele[i].row ||
             (b.ele[j].row == a.ele[i].row && b.ele[j].col < a.ele[i].col))
      c.ele[k++] = b.ele[j++];
    else {
      c.ele[k] = a.ele[i];
      c.ele[k++].val = a.ele[i++].val + b.ele[j++].val;
    }
  }
  while (i < a.num)
    c.ele[k++] = a.ele[i++];
  while (j < b.num)
    c.ele[k++] = b.ele[j++];
  c.num = k;
  return c;
}

int main() {
  Sparse a, b;
  a.rows = 3;
  a.cols = 3;
  a.num = 2;
  a.ele = new Element[2]{{0, 0, 5}, {1, 1, 7}};
  b.rows = 3;
  b.cols = 3;
  b.num = 2;
  b.ele = new Element[2]{{0, 0, 3}, {2, 2, 6}};
  Sparse c = add(a, b);
  for (int i = 0; i < c.num; i++)
    cout << c.ele[i].row << " " << c.ele[i].col << " " << c.ele[i].val << endl;
}
