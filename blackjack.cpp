// Assignment 2 Amelie Cameron
// This program is a simplified version of blackjack for 1 player
// The player is dealt two cards and the can continue to draw until they get close to 21 or bust

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main()
{
  int card_1, card_2, new_card, total;
  char answer;
  char play_again = 'y';
  bool game_over;

  while(play_again == 'y')
    {  
      game_over = false;
      srand(time(NULL));
      
      card_1 = rand() % 10 +1;
      card_2 = rand() % 10 +1;
      
      cout << "First cards: " << card_1 << ", " << card_2 <<endl;
      
      total = card_1 + card_2;
      
      cout << "Total:" << total << endl;
      
      while(!game_over)
	{
	  cout << "Do you want another card? (y/n):"<<endl;
	  cin >> answer;
	  if (answer == 'y'){
	    new_card = rand() % 10 +1;
	    cout << "Card: "<< new_card <<endl;
	    total += new_card;
	    cout << "Total: " << total <<endl;
	    if (total > 21) {
	      cout << "Bust" << endl;
	      game_over = true;
	    }
	  } else if(answer == 'n') {
	      game_over = true;
	  }
	}
      cout << "Would you like to play again? (y/n)" <<endl;
      cin >> play_again; 
    }

} 
   


