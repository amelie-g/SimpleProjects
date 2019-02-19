#include <iostream>
#include <string>

using namespace std;

char getMostFreqLetter(string s)
{
  const int NUM_ASCII = 128;
  int ascii_array[NUM_ASCII] = { };
  int max = 0;
  int maxIndex = 0;
  for(int i = 0; i < s.length(); ++i)
    {
      if (s[i] == ' ')
	continue;
      ascii_array[(int)s[i]]++;
    }
  for(int i = 0; i < NUM_ASCII; i++)
    {
      if(ascii_array[i] > max)
	{
	  max = ascii_array[i];
	  maxIndex = i;
	}
    }
  return (char)maxIndex;
}

void StrToTokens(string s)
{
  char newChar;
  string temp = "";
  for(int i=0; i < s.length(); i++)
    {
      if(s[i] != ' ')
        {
	  temp += s[i];
	  if (i == s.length() - 1) {
	      cout << " '" << temp << "'\n";
	  }
	}
      else {
	cout << " '" << temp << "',";
	temp = "";
      }
    }
}

int main() 
{
  string s = "Life is not a problem to be solved but a reality to be experienced.";
  cout << "The string to convert to separate tokens: '" << s << "'" << endl;
  cout << endl;
  StrToTokens(s);
  char maxCharacter = getMostFreqLetter(s);
  cout << endl;
  cout << "Most Frequent Letter: " << maxCharacter << endl;
}
