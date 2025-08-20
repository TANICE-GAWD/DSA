#include <iostream>
using namespace std;

struct Element {
  int row, col, val;
};

struct Sparse {
  int rows, cols, num;
  Element *ele;
};

Sparse transpose(Sparse s) {
  Sparse t;
  t.rows = s.cols;
  t.cols = s.rows;
  t.num = s.num;
  t.ele = new Element[t.num];
  int k = 0;
  for (int i = 0; i < s.cols; i++)
    for (int j = 0; j < s.num; j++)
      if (s.ele[j].col == i) {
        t.ele[k].row = s.ele[j].col;
        t.ele[k].col = s.ele[j].row;
        t.ele[k++].val = s.ele[j].val;
      }
  return t;
}

int main() {
  Sparse s;
  s.rows = 3;
  s.cols = 3;
  s.num = 3;
  s.ele = new Element[3]{{0, 0, 5}, {1, 1, 8}, {2, 2, 9}};
  Sparse t = transpose(s);
  for (int i = 0; i < t.num; i++)
    cout << t.ele[i].row << " " << t.ele[i].col << " " << t.ele[i].val << endl;
}
