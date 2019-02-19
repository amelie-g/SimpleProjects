#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    printf("Please enter two numbers: ");
    cin >> a >> b;
    printf("larger=%d and smaller=%d\n", a, b);
    while (b != 0) {
    	  int r = a % b;
	  a = b;
	  b = r;
	  
	  }
    printf("Greatest common divisor is %d\n", a);

	return 0; 
}
