#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
using namespace std;

int binary_search(int arr[], int find, int imin, int imax)
{
  int imid = (imin + imax) / 2;

  if(arr[imid] > find)
    return binary_search(arr, find, imin, imid-1);
  else if (arr[imid] < find)
    return binary_search(arr, find, imid+1, imax);
  else
    return imid;
}

int main() {

  srand(time (0));

  int arr[96] = {0};

  for(int i = 0; i < 96; i++) { 
    arr[i] = rand() % 100 + 1;
  }

  cout << "The original array: " << endl;
  for(int i=0; i < 96; i++) {
    std::cout << arr[i] << ' ';
  }

  int elements = sizeof(arr) / sizeof(arr[0]);
  std::sort(arr, arr + elements);
  cout << endl;
  cout << endl;
  cout << "Sorted array using binary search: " << endl;
  for(int i = 0; i < elements; i++)
    std::cout << arr[i] << ' ';
  
  int find;
  cin >> find;
  int imid = binary_search(arr, find, 0, 96); 
  cout << endl;
  cout << imid << endl;

  return 0;
}
