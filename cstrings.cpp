//Amelie Cameron Assignment 7 CStrings
// This program implements functions that deal with null terminated C-Style strings.
// The 6 functions accomplish the following: 1-return the last index ofa target char, 2-reverses any string passed in, 3-replaces all target chars with a replacement char,  4-finds the first index of a substring in any given string, 5-finds if a given string is a palindrome, 6- EXTRA reverses the words in a given string.
 
#include <iostream>
#include <string>
#include <cstring>
using namespace std; 

int lastIndexOf(char *s, char target)
{
  int index = 0;
  int size = strlen(s);

  for(int i = 0; i < size; i++)
    {
     if(s[i] == target)
	index = i;
    }
  return index;
}

void reverse2(char *s,int begin,int end)
{
  int i, j;
  for(i = begin, j = end; i<j; i++, j--)
    {
      char temp = s[i];
      s[i] = s[j];
      s[j] = temp;
    }
}

void reverse(char *s)
{
  reverse2(s, 0, strlen(s)-1);  
}

bool isPalindrome(char *s)
{
  int size = strlen(s);
  char n[size];
  strcpy(n, s);
  reverse(n);
  for(int i = 0; i < size; ++i) 
    {
    if(s[i] != n[i]) 
      return false;
    }
  return true;
}

int replace(char *s, char target, char replacementChar)
{
  int size = strlen(s);
  int count = 0;

  for(int i = 0; i < size; i++)
    {
      if(s[i] == target)
	{
	  s[i] = replacementChar;
	  count++;
	}   
    }

  for(int i = 0; i < size; i++)
    cout << s[i];
  cout << endl;
  cout << "Replacements made: " << count << endl;
  return count;
}

int findSubString(char *s, char substring[])
{
  int size = strlen(s); 
  int subsize = strlen(substring);
  char compare[subsize+1];
  int substringIndex = -1;
  for(int i = 0; i < size; i++)
    {
      if(s[i] == substring[0])
	{
	  strncpy(compare, s + i, subsize);
	  compare[subsize] = '\0'; 
	  
	  if(strcmp(substring, compare) == 0)
	    substringIndex = i;
	}
    }
  return substringIndex;
}

void reverseWords(char *s) 
{
  
  int length = strlen(s);
  reverse(s);
  int lastWhitespace = 0;

  for(int i = 0; i < length; i++) 
    {
      if(s[i] == ' ')
	{
	  reverse2(s, lastWhitespace, i-1);
	  lastWhitespace = i + 1;
	}
    }
}

int main()
{
  char str[] = "This is a sample string";
  char target = 's';
  int lastIndex;
  char replacementChar = 'A';
  cout << endl;
  cout << "Original string: " << str << endl;
  lastIndex = lastIndexOf(str, target);
  cout << endl;
  cout << "#1: Last index of the char '" << target << "' in the string is: " << lastIndex << endl;

  cout << endl;
  cout << "#2: The reversed form of the string: " << endl;
  reverse(str);
  for(int i = 0; i < strlen(str); ++i)
    cout << str[i];
  cout << endl;

  cout << endl;
  cout << "#3: Replace target char '" << target << "' with '" << replacementChar <<  "': "<< endl;
  replace(str, target, replacementChar);
  cout << endl;

  char amelie[] = "amelie";
  char substring[] = "li";
  cout << "The second sample string is '" << amelie << "' and the substring is '" << substring << "'"<< endl; 
  cout << "#4: First index of substring '" << substring << "' (-1 if n/a): ";
  cout << findSubString(amelie, substring) << endl;

  isPalindrome(str);
  char pal[] = "abcba";
  cout << endl;
  cout << "The string array named pal is: " << pal << endl;
  cout <<"#5: Is the string array named 'pal' a palindrome? (1 True, 0 False): " << isPalindrome(pal) << endl;
  cout <<endl;

  char extrastring[] = "This is another sample string";
  cout << "Extra string is: " << extrastring << endl; 
  reverseWords(extrastring);
  cout << "#6: Extra Credit: Reversed words in string: " << endl;
  for(int i = 0; i < strlen(extrastring); i++)
    cout << extrastring[i];
  cout << endl;

return 0;
}
