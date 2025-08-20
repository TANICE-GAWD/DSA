#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1 = "Hello ";
  string s2 = "World";
  s1 += s2;
  cout << "Concatenated: " << s1 << "\n";
}
