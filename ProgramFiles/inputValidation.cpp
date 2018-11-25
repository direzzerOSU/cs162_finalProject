/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
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

//// prompts the user to re-enter the intended attribute's value (for a char value); 
//// however, makes sure that the entire line of text is captured (doesn't
//// trigger loops looking for 'f'
//void charValidationLine(char& value) {
//   std::string s;
//   while(cin.fail()){
//      cin.clear();
//      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
//      cout << "You have entered the wrong type of input. \n   Please enter a character: ";
////      cin >> value;
//      getline(cin, s, '\n');
//      cout << endl;
//   }
//   value = s[0];
//}

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

// validMMChoice = "Valid Main Menu Choice"
//    this function is tailored to the OSU IMS (Oregon State University Information Management System)
//    evaluates the user's input to make sure that a char was entered & ensures the char is a valid menu option
void validMMChoice(char& value) {
   while(cin.fail() || (tolower(value) != 'a' && tolower(value) != 'b' && tolower(value) != 'c' && tolower(value) != 'd' && tolower(value) != 'e' && tolower(value) != 'f')) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
      cout << "You did not select a valid menu option...\n  Please enter a valid menu option: ";
      cin >> value;
      cout << endl;
   }
}

// validYesNo = "Valid Yes or No selection"
//    evaluates the user's input to make sure that a char was entered & ensures the char is either a Y or N (for yes and no, respectively)
void validYesNo(char& value) {
   while(cin.fail() || (tolower(value) != 'y' && tolower(value) != 'n')) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
      cout << "You did not select a valid option...\n  Please enter a valid option: ";
      cin >> value;
      cout << endl;
   }
}

// verify one of the three (building) attributes is chosen
void validBldgChoice(char& value) {
   while(cin.fail() || (tolower(value) != 'a' && tolower(value) != 'b' && tolower(value) != 'c' && tolower(value) != 'd')) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      cout << "You did not select a valid option for editing an attribute...\n  Please enter a valid option: ";
      cin >> value;
      cout << endl;
   }
}

// verify one of the two (people: instructor/student) attributes is chosen
void validTypeChoice(char& value) {
   while(cin.fail() || (tolower(value) != 'a' && tolower(value) != 'b')) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      cout << "You did not select a valid option...\n  Please enter a valid option: ";
      cin >> value;
      cout << endl;
   }
}
