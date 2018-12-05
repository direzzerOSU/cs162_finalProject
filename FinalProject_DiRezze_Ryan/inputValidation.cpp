/*********************************************************************
** Program name: Monster Hunting Game
** Author: Ryan DiRezze
** Date: December 4, 2018
** Description: Implements input validation functions.
*********************************************************************/

// include the function's header with its function prototype
#include "inputValidation.hpp"

// prompts the user to re-enter the intended attribute's value (for an int value)
void intValidation(int& value) {
   while(cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
      cout << "You have entered the wrong type of input. \n   Please enter an integer: ";
      cin >> value;
      cout << endl;
   }
}

// prompts the user to re-enter the intended attribute's value (for a char value)
void charValidation(char& value) {
   while(cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
      cout << "You have entered the wrong type of input. \n   Please enter a character: ";
      cin >> value;
      cout << endl;
   }
}

// prompts the user to re-enter the intended attribute's value (for an int value)
void floatValidation(float& value) {
   while(cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
      cout << "You have entered the wrong type of input. \n   Please enter a float: ";
      cin >> value;
      cout << endl;
   }
}

// validYesNo = "Valid Yes or No selection"
//    evaluates the user's input to make sure that a char was entered & ensures the char is either a Y or N (for yes and no, respectively)
void validYesNo(int& value) {
   while(cin.fail() || (value != 1 && value != 2)) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
      cout << "You did not select a valid option...\n  Please enter a valid option: ";
      cin >> value;
	  intValidation(value);
   }
}

// ensure that the user's input is a valid menu selection based on the player's lineup
void validMonsterSelection(Character* c, int& choice) {
	while (choice > static_cast<Trainer*>(c)->getLineupQty() || choice <= 0) {
		cout << "Whoops! You didn't select a valid monster... Please try again..." << endl;
		cout << "Selection: ";
		cin >> choice;
		intValidation(choice);
	}
}
