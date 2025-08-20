#include <iostream>
using namespace std;

int main() {
  char ch = 'A';
  if (ch >= 'A' && ch <= 'Z') {
    ch = ch - 'A' + 'a';
  }
  cout << "Lowercase: " << ch << "\n";
}
