#include <iostream> 
using namespace std;

void reverse(int number) {
  if(number == 0)
    return; 
  else {
    cout << number % 10;
    reverse(number/10);
  }
} 

int main() {
  int number;

  cout << "Enter a positive decimal integer: " << endl;
  cin >> number;
  
  cout << "Integer in reverse: " << endl;
  reverse(number);
  cout << endl;
 
  return 0;
}
