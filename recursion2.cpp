#include <iostream>
#include <string>
using namespace std;

void writeBackward2(string s) {
  int length = s.size();
  if(length > 0) {
    writeBackward2(s.substr(1, length-1));
    cout << s.substr(0,1);
  }
}

int main() {
  string s ("A character sequence");

  cout << "Enter a character string: " << endl;
  getline(cin, s);

  cout << "String in reverse: " << endl;
  writeBackward2(s);
  cout << endl;

  return 0;
}

