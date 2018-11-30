/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Implements the main menu and other menu-like
   functions.
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"

// game introduction menu
void introMenu(bool& status) {
   // introduction
   string program_name = "Pokemon Hunting Game";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;
   
   cout << "What would you like to do?" << endl;
   cout << "   1. Play game" << endl;
   cout << "   2. Exit" << endl;
   cout << endl << "Selection: ";
   int quit;
   cin >> quit;
   intValidation(quit);
   cout << endl;

   // catch wrong inputs
   while(quit != 1 && quit != 2) {
      cout << "Whoops! You didn't enter a valid menu option... Please try again." << endl;
      cout << "   Selection: ";
      cin >> quit;
      intValidation(quit);
   }

   // begin the game
   if(quit == 1) {
	   instructions(status);
   }
   else if(quit == 2) {
	   // end the game
	   status = false;
   }
}

// valid yes/no option input validation
void yesOrNo(int x) {
	// ensure a valid choice is entered (1. Yes) or (2. No)
	while (x != 1 && x != 2) {
		cout << "Oops! You didn't enter a valid choice for yes or no... Please try again." << endl;
		cin >> x;
		intValidation(x);
	}
}

// gameplay instructions before beginning gameplay
void instructions(bool& status) {
	// instructions
	cout << "Welcome to the Pokemon Hunting Game!" << endl << endl;
	cout << "Objective: Catch the Queen Kitty pokemon" << endl;
	cout << "	       Fight wild pokemon to collect items & gold" << endl;
	cout << "	       Use gold to purchase items" << endl;

	// prompt to begin the game
	cout << "Are you ready to begin the game?" << endl;
	cout << "	1. Yes" << endl;
	cout << "	2. No" << endl;
	int input = 9;
	cin >> input;
	intValidation(input);

	// verify a valid menu option is chosen
	while (input != 1 && input != 2) {
		cout << "Uh oh! You didn't enter a valid option... Please try again..." << endl;
		cout << "Selection: ";
		cin >> input;
		intValidation(input);
	}

	// start the game
	if (input == 1) {
		cout << "Starting game..." << endl;
		status = true;
	}

	// return to the main menu
	else if (input == 2) {
		mainMenuReturn(status);
	}

	// catch an error (intValidation() not working as intended)
	else {
		cout << "[ERROR] instructions(bool& status) intValidation(int) didn't work as intended..." << endl;
	}
}

// primary menu that users use to navigate the program
void GameMenu(int& option1) {
   
   // ensure a valid character is chosen for team #1
   while(option1 != 1 && option1 != 2 && option1 != 3 && option1 != 4 && option1 != 5 && option1 != 6) {
      // menu prompt
      cout << "Please select an option from the following choices:" << endl;
      cout << "Input the option1's corresponding letter to make a selection..." << endl << endl;
      
      // menu choices
      cout << "    1. Vampire" << endl;
      cout << "    2. Barbarian" << endl;
      cout << "    3. Blue Men" << endl;
      cout << "    4. Medusa" << endl;
      cout << "    5. Harry Potter" << endl;
      cout << "    6. Exit" << endl;

      cout << endl << "Player Selection: ";
      cin >> option1;
      intValidation(option1);

      if(option1 != 1 && option1 != 2 && option1 != 3 && option1 != 4 && option1 != 5 && option1 != 6) {
         cout << endl;
         while(option1 != 1 && option1 != 2 && option1 != 3 && option1 != 4 && option1 != 5 && option1 != 6) {
            cout << "Uh oh! It looks like you didn't input a valid menu option1... Please try again." << endl << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Team #1: ";
            cin >> option1;
            cout << endl;
         }
      }
      if(option1 == 6) {
         break;
      }
   }
}

// a small prompt that asks the user if he/she would like to return to the main
// menu; this was intended to appear after the user performs some transaction
void mainMenuReturn(bool& status) {
   int option = 0;
   while(option != 9 && option != 5) {
      cout << "Do you want to return to the main menu?" << endl;
      cout << "   1. Yes" << endl;
      cout << "   2. No" << endl;
      cout << endl << "Selection: ";
      cin >> option;
      intValidation(option);

      if(option == 1) {
         option = 9;       // let the program escape the 'while loop' & return to the menu
         status = true;
      }
      
      else if(option == 2) {
         cout << endl << "Do you want to exit the program?" << endl;
         cout << "   1. Yes" << endl;
         cout << "   2. No" << endl;
         cout << endl << "Selection: ";
         cin >> option;
         intValidation(option);
         
         // escape the 'while loop' & quit the program
         if(option == 1) {
            option = 5;
            status = false;
         }
         
         // do nothing and let the program run back through the 'while loop'
         else if(tolower(option) == 2) {
            //option = 'n'
         }
      }
   }
}

// menu for the player to move his/her player within the board
void movePlayer() {
	// menu choices
	cout << "Where would you like to move?" << endl;
	cout << "	1. Up" << endl;
	cout << "	2. Right" << endl;
	cout << "	3. Down" << endl;
	cout << "	4. Left" << endl;

	// user input / menu selection
	cout << endl << "Selection: ";
	int selection = 0;
	cin >> selection;
	intValidation(selection);

	// ensure a valid menu option is chosen
	while (selection != 1 && selection != 2 && selection != 3 && selection != 4) {
		cout << endl << "Whoops! That's not a valid menu choice... Please try again..." << endl;
		cout << endl << "Selection: ";
		cin >> selection;
		intValidation(selection);
	}

	// move up
	if (selection == 1) {
	}

	// move right
	else if (selection == 2) {
	}

	// move down
	else if (selection == 3) {
	}

	// move left
	else if (selection == 4) {
	}

	// catch an error with debugging
	else {
		cout << endl << "[ERROR] void movePlayer()" << endl << endl;
	}
}