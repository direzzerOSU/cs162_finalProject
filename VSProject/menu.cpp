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
   string program_name = "Queen Kitty Hunting Game";
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
void yesOrNo(int& x) {
	// prompt the menu choices
	cout << "Yes or no?" << endl;
	cout << "	1. Yes" << endl;
	cout << "	2. No" << endl;

	// acquire user input
	cout << "Selection: ";
	cin >> x;
	intValidation(x);

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
	cout << "Welcome to the Monster Hunting Game!" << endl << endl;
	cout << "Objective: Defeat the Queen Kitty Monster (Final Boss)" << endl;
	cout << "	   Fight wild monsters to collect items" << endl;

	// prompt to begin the game
	cout << endl << "Are you ready to begin the game?" << endl;
	cout << "	1. Yes" << endl;
	cout << "	2. No" << endl;
	int input = 9;
	cout << endl << "Selection: ";
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
		cout << endl << "Starting game..." << endl;
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
			 //option = 5;
         }
      }
   }
   cout << endl;
}

// menu for the player to move his/her player within the board
void movePlayer(Board* b, Character* c) {

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

	// helps determine whether the char can move on the game board
	bool runFromFight;

	// move up
	if (selection == 1) {
		// if the space is occupied
		if (b->upSpaceCheck(c)) {
			cout << "A monster occupies the space you're trying to move to..." << endl;
			cout << "If you want to move to the new space, you must defeat the monster..." << endl;
			cout << endl << "Do you want to fight the monster?" << endl;

			int selection = -10;
			yesOrNo(selection);

			// fight the monster
			if (selection == 1) {
				// fight the monster
				Character* m = b->upMonster(c);
				b->fightWithResult(c, m, runFromFight);

				// if monster is defeated, remove monster from the board
				if (!static_cast<Trainer*>(c)->emptyLineup() && runFromFight == false) {
					delete m;
					b->moveUp(c);
				}
				// if player is defeated
				else {
					cout << "Uh oh... You have been defeated..." << endl;
				}
			}

			// do not fight the monster
			else if (selection == 2) {
				cout << endl << "You decide to leave the enemy monster alone..." << endl;
				// let the function end & return to the round/turn menu to re-select a new move or something else
			}
			
			// catch a bug (wrong input)
			else {
				cout << "[BUG] yesOrNo(selection) in: movePlayer(Board*, Character*)..." << endl;
			}
		}
		else {
			b->moveUp(c);
		}
	}

	// move right
	else if (selection == 2) {
		// if the space is occupied
		if (b->rightSpaceCheck(c)) {
			cout << "A monster occupies the space you're trying to move to..." << endl;
			cout << "If you want to move to the new space, you must defeat the monster..." << endl;
			cout << endl << "Do you want to fight the monster?" << endl;

			int selection = -10;
			yesOrNo(selection);

			// fight the monster
			if (selection == 1) {
				// fight the monster
				Character* m = b->rightMonster(c);
				b->fight(c, m);

				// if monster is defeated, remove monster from the board
				if (!static_cast<Trainer*>(c)->emptyLineup() && runFromFight == false) {
					delete m;
					b->moveRight(c);
				}
				// if player is defeated
				else {
					cout << "Uh oh... You have been defeated..." << endl;
				}
			}

			// do not fight the monster
			else if (selection == 2) {
				// let the function end & return to the round/turn menu to re-select a new move or something else
			}

			// catch a bug (wrong input)
			else {
				cout << "[BUG] yesOrNo(selection) in: movePlayer(Board*, Character*)..." << endl;
			}
		}
		else {
			b->moveRight(c);
		}
	}

	// move down
	else if (selection == 3) {
		// if the space is occupied
		if (b->downSpaceCheck(c)) {
			cout << "A monster occupies the space you're trying to move to..." << endl;
			cout << "If you want to move to the new space, you must defeat the monster..." << endl;
			cout << endl << "Do you want to fight the monster?" << endl;

			int selection = -10;
			yesOrNo(selection);

			// fight the monster
			if (selection == 1) {
				// fight the monster
				Character* m = b->downMonster(c);
				b->fight(c, m);

				// if monster is defeated, remove monster from the board
				if (!static_cast<Trainer*>(c)->emptyLineup() && runFromFight == false) {
					delete m;
					b->moveDown(c);
				}
				// if player is defeated
				else {
					cout << "Uh oh... You have been defeated..." << endl;
				}
			}

			// do not fight the monster
			else if (selection == 2) {
				// let the function end & return to the round/turn menu to re-select a new move or something else
			}

			// catch a bug (wrong input)
			else {
				cout << "[BUG] yesOrNo(selection) in: movePlayer(Board*, Character*)..." << endl;
			}
		}
		else {
			b->moveDown(c);
		}
	}

	// move left
	else if (selection == 4) {
		// if the space is occupied
		if (b->leftSpaceCheck(c)) {
			cout << "A monster occupies the space you're trying to move to..." << endl;
			cout << "If you want to move to the new space, you must defeat the monster..." << endl;
			cout << endl << "Do you want to fight the monster?" << endl;

			int selection = -10;
			yesOrNo(selection);

			// fight the monster
			if (selection == 1) {
				// fight the monster
				Character* m = b->leftMonster(c);
				b->fight(c, m);

				// if monster is defeated, remove monster from the board
				if (!static_cast<Trainer*>(c)->emptyLineup() && runFromFight == false) {
					delete m;
					b->moveLeft(c);
				}
				// if player is defeated
				else {
					cout << "Uh oh... You have been defeated..." << endl;
				}
			}

			// do not fight the monster
			else if (selection == 2) {
				// let the function end & return to the round/turn menu to re-select a new move or something else
			}

			// catch a bug (wrong input)
			else {
				cout << "[BUG] yesOrNo(selection) in: movePlayer(Board*, Character*)..." << endl;
			}
		}
		else {
			b->moveLeft(c);
		}
	}
	// catch an error with debugging
	else {
		cout << endl << "[ERROR] void movePlayer()" << endl << endl;
	}

	// 50% chance to find an item
	static_cast<Trainer*>(c)->randomItem();
}

// player menu that appears at the start of each turn
void turnMenu(Board* b, Character* c) {
	cout << "What would you like to do? Please use the menu to move and manage your character..." << endl;

	// display menu
	cout << endl << "Menu: " << endl;
	cout << "	1. Move player" << endl;
	cout << "	2. View lineup of monsters" << endl;
	cout << "	3. View backpack of items" << endl;
	cout << "	4. Quit the current game" << endl;

	// accept user input
	int x = -10;
	cout << endl << "Selection: ";
	cin >> x;
	intValidation(x);

	// verify a valid menu option was chosen
	while (x != 1 && x != 2 && x != 3 && x != 4) {
		cout << "Whoops! You didn't select a valid menu option... Please try again..." << endl;
		cin >> x;
		intValidation(x);
	}
	cout << endl;

	// move player
	if (x == 1) {
		movePlayer(b, c);
	}

	// view lineup of monsters
	else if (x == 2) {
		monsterMenu(c);
	}

	// view backpack items
	else if (x == 3) {
		static_cast<Trainer*>(c)->useItemPrompt();
	}

	// quit the current game
	else if (x == 4) {
		cout << "Are you sure you want to quit the game?" << endl << endl;
		int input = -10;
		yesOrNo(input);
		validYesNo(input);

		// quit the game after verifying with the user
		if (input == 1) {
			static_cast<Trainer*>(c)->gameOver();
		}
	}
}

// menu for the player to navigate, including contents of:
//      view monsters in player's lineup, monsters' attributes, etc.
void monsterMenu(Character* player) {
	cout << "Your lineup contains the following characters: " << endl;
	
	// loop through each monster in the player's lineup
	for (int k = 0; k < static_cast<Trainer*>(player)->getLineupQty(); k++) {
		cout << "	" << k + 1 << ". " << static_cast<Trainer*>(player)->getMonster(k)->getType() << endl;
		cout << "		Health: " << static_cast<Trainer*>(player)->getMonster(k)->getHealth() << endl;
		cout << "		Speed:  " << static_cast<Trainer*>(player)->getMonster(k)->getSpeed() << endl;
		cout << "		Armor:  " << static_cast<Trainer*>(player)->getMonster(k)->getArmor() << endl;
	}
	cout << endl << "Please select a monster from your lineup..." << endl;
	cout << "Or please select 9 if you'd like to return to the main menu..." << endl;

	// acquire user input (select the monster)
	int monster = -10;
	cout << endl << "Monster Selection: ";
	cin >> monster;
	intValidation(monster);

	if (monster != 9)
	{
		// verify the input is legal
		validMonsterSelection(player, monster);

		// ask what the person would like to do
		cout << endl << "What 'action' would you like to do with the monster? (Select the monster's corresponding integer)" << endl;
		cout << "	1. Use item" << endl;
		cout << "	2. Return to menu" << endl;

		// acquire user input (for what to do with a monster in the lineup)
		int action = -10;
		cout << "What to do with monster?: ";
		cin >> action;
		intValidation(action);

		// verify the input is legal based on available menu
		while (action != 1 && action != 2) {
			cout << "Whoops! That's not a legal menu option... Please try again..." << endl;
			cout << "Action Selection: ";
			cin >> action;
			intValidation(action);
		}

		// use items
		if (action == 1) {
			// use item on the selection monster ("monster")
			if (!static_cast<Trainer*>(player)->emptyBackpack())
			{
				static_cast<Trainer*>(player)->useItemMonster(static_cast<Trainer*>(player)->getMonster(monster));
			}

			// backpack is empty
			else
			{
				cout << "Your backpack is empty..." << endl;
			}
		}
	}
}