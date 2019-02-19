#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 32;

void print(int* input)
{
  for(int i = 0; i < SIZE; i++)
    cout << input[i] << " ";
  cout << endl;
}


void selectionSort(int arr[])
{
  int i, j, min, temp;
  int count = 0;
  for(i = 0; i < SIZE; i++)
    {
      min = i;
      for(j = i+1; j < SIZE; j++) 
	{
	  if(arr[j] < arr[min])
	    min = j;
	  count++;
	}
      if(min != i)
	{
	  temp = arr[i];
	  arr[i] = arr[min];
	  arr[min] = temp;
	  count++;
	} 
    }
  cout << "Counter is: " << count << endl; 
}

int main() {
  srand(time(NULL));

  cout << "The array consists of " << SIZE << " elements: " << endl;

  int input[SIZE] = { 0 };

  for(int i = 0; i < SIZE; i++)
    {
      int j = rand() % 100+1;
      input[i] = j;
    }

  cout << "Input: " << endl;
  print(input);

  selectionSort(input);

  cout << "Output: " << endl;
  print(input);
  
  return 0;
}
