//Amelie Cameron Assignment 10
//This program is a classic number guessing game. The program guesses a user's number between 1 and 100. Unlike the previous assignment, this one uses a NumberGuesser class that contains all of the logic for remembering the current state of the programs guesses and implements the binary search algorithm.

#include <iostream>
#include <algorithm>
#include "NumberGuesser.h"
using namespace std;

int main()
{
 
  char value;
  bool done = false;
  bool playAgain = true;
  char play;
  
  NumberGuesser guesser (1, 100);  

  while(playAgain)
  {
    guesser.reset();
    
    cout << "Think of a number between 1 and 100" << endl;
    
    while(!done) 
      {
	int imid = guesser.getCurrentGuess();
	
	cout << "Is the number " << imid << "? (h/l/c) :" << endl;
	cin >> value;
    
	if(value == 'h')
	  guesser.higher(); 
	else if(value == 'l')
	  guesser.lower();
	else if(value == 'c') 
	  {
	    cout << "You picked " << imid << "? Great pick. " << endl;
	    cout << "Would you like to play again? (y/n)" << endl;
	    cin >> play;
	    if(play == 'y') {
	      playAgain = true;
	      done = true;
	    } else if(play == 'n')
	      {
		playAgain = false;
		done = true;
		cout << "Thanks for playing!" << endl;
	      }
	    else
	      {
		cout << "Incorrect key. Goodbye." << endl;
		playAgain = false;
	        done = true;
	      } 
	  }
	else 
	  cout << "Incorrect key. Please enter h, l, or c." << endl;
      }
    done = false;
  }
 return 0;
}
