#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


const int SIZE = 32;
int comp = 0;

void print(int* input)
{
  for(int i = 1; i <= SIZE; i++)
    cout << input[i] << " ";
  cout << endl;
}


void q_sort(int arr[], int left, int right)
{
  int i = left, j = right;
  int temp;
  int pivot = arr[(left + right) / 2];
  
  while(i <= j)
     {
      while(arr[i] < pivot)
	{
	  i++;
	  comp++;
	}
      while(arr[j] > pivot)
	{
	  j--;
	  comp++;
	}
      if(i <= j)
	{
	  temp = arr[i];
	  arr[i] = arr[j];
	  arr[j] = temp;
	  i++;
	  j--;
	  comp++;
	}
     };
  
  if(left < j){
    q_sort(arr, left, j);
  }
  if(i < right){
    q_sort(arr, i, right);
  }
}



int main()
{
  srand(time(NULL));

 cout << "The array consists of " << SIZE << " elements: " << endl;

 int input[SIZE+1] = { 0 };
 
 for(int i = 1; i <= SIZE; i++)
  {
    int j = rand() % 100+1;
    input[i] = j;
  }
 
 cout << "Input: " << endl;
 print(input);
 
 q_sort(input, 1, SIZE);
 
 cout << "Output: " << endl;
 print(input);

 cout << "Count: " << comp << endl;
 
 return 0;
}
