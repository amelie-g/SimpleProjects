//Assignment 6: Amelie Cameron
//This program takes in a valid string containing an infix expression. It then converts it to a postfix expression, computes and returns the result.

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;


bool isOperator(char input)
{
  char arr[] = {'-', '+', '*', '/'};
  for(int i = 0; i < 4; i++)
    {
      if(input == arr[i])
        {
          return true;
        }
    }
  return false;
}

bool isOperand(char input)
{
  if(input >= 48 && input <= 57)
    {
      return true;
    }
  return false;
}

string InfixToPostfix(string input)
{
  stack<char> calcStack;
  string postfixExp = "";
  for(int i = 0; i < input.length(); i++)
    {
      if(isOperator(input[i]))
        {
          while((!calcStack.empty()) && (calcStack.top() != '('))
            {
              postfixExp += calcStack.top();
              calcStack.pop();
            }
          calcStack.push(input[i]);
        }
      else if(isOperand(input[i]))
        {
          postfixExp += input[i];
        }
      else if(input[i] == '(')
        {
          calcStack.push(input[i]);
        }
      else if(input[i] == ')')
        {
          while((!calcStack.empty()) && (calcStack.top() != '('))
            {
              postfixExp += calcStack.top();
              calcStack.pop();
            }
          calcStack.pop();
        }
    }
  while(!calcStack.empty())
    {
      postfixExp += calcStack.top();
      calcStack.pop();
    }
  return postfixExp;
}

int ctoi(char c)
{
  return c - '0';
}

void performOp(string input)
{
  stack<int> calcStack;
  int operand1, operand2;
  int result;
  int i=0;
  while (i < input.length()) 
    {
      
      if(isOperand(input[i]))
        {
	  calcStack.push(ctoi(input[i]));
	}      
      else
        {
	  operand2 = calcStack.top();
	  calcStack.pop();
	  operand1 = calcStack.top();
	  calcStack.pop();
	   
	  switch(input[i])
	    {
	    case '+': result = operand1 + operand2;
	      calcStack.push(result);
	      break;
	    case '-': result = operand1 - operand2;
	      calcStack.push(result);
	      break;
	    case '*': result = operand1 * operand2;
	      calcStack.push(result);
	      break;
	    case '/': result = operand1 / operand2;
	      calcStack.push(result);
	      break;   
	    }
        }
      i++;
    }
    
  while (!calcStack.empty()) 
    {
      calcStack.pop();
    }
      
  cout << "The result is: " << result << endl;
}


int main()
{
  string input;
  string postfixExp;
  int result;
  stack<char> calcStack;

  cout << "Enter an infix expression: " << endl;
  getline(cin, input);
  postfixExp = InfixToPostfix(input);

  cout << "Converted to postfix expression: " << endl;
  cout << postfixExp << endl;
 
  performOp(postfixExp);
  
  return 0;
}



