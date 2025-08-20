#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
  c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
  string s = "Hello World";
  int write = 0;
  for (int read = 0; read < s.size(); read++) {
    if (!isVowel(s[read])) {
      s[write++] = s[read];
    }
  }
  s.resize(write);
  cout << "Without vowels: " << s << "\n";
}
