#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 32;
const int NUM_BUCKETS = 100;

void print(int* input)
{
  for(int i = 1; i <= SIZE; i++)
    cout << input[i] << " ";
  cout << endl;
}

void bucketSort(int* input)
{
  int comp = 0;
  int count[NUM_BUCKETS+1] = { 0 };
 
  for(int i = 1; i <= SIZE; i++)
    {
      count[input[i]]++;
      comp++;
    }
    
  int curIndex = 1;
  for(int i = 1; i <= NUM_BUCKETS; i++)
    { 
      int curCount = count[i];
      comp++;
      for(int j = 0; j < curCount; j++)
	{
	  input[curIndex] = i;
	  curIndex++;
	  comp++;
	}
    }
  cout << "Count: " << comp << endl;
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

  bucketSort(input);
 
  cout << "Output: " << endl;
  print(input);

  return 0;
}
