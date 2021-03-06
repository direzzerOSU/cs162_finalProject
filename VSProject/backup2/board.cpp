/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "board.hpp"

// initialize the playing board with a border
Board::Board() {
	board = new Character**[dimensions];	// 10x10 dimensions

	for (int n = 0; n < dimensions; n++) {
		board[n] = new Character*[dimensions];

		// reset all pointers to nullptr
		for (int i = 0; i < dimensions; i++) {
			board[n][i] = nullptr;
		}
	}
}

// game board destructor
Board::~Board() {
	for (int n = 0; n < dimensions; n++) {

		// reset all pointers to nullptr
		for (int i = 0; i < dimensions; i++) {
			delete board[n][i];
		}

		delete[] board[n];
	}

	delete[] board;
}

// prints the current game board
void Board::print() {
	// print the top border of the board
	cout << "  -";
	for (int x = 0; x < dimensions; x++) {
		cout << "---";
	}
	cout << "----" << endl;
	// print the board with outside border
	for (int r = 0; r < dimensions; r++) {
		cout << "  | ";
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == nullptr) {
				cout << "   ";
			}
			else if (board[r][c]->getType() == "Trainer") {
				cout << " T ";
			}
			else {
				cout << " ? ";
			}
		}
		cout << "  |" << endl;
	}
	// print the bottom border of the board
	cout << "  -";
	for (int x = 0; x < dimensions; x++) {
		cout << "---";
	}
	cout << "----" << endl;

	// print the player's health info
	cout << endl << "Your remaining health: " << player->getHealth() << endl << endl;
}

// executes a fight between the player and a (sole) monster (on the board)
void Board::fight(Character* player, Character* monster) {
	bool fightOver = false;
	cout << endl << "----------------------------------------" << endl << endl;

	// fights until either all player's monsters die or the opponent monster dies
	while ((static_cast<Trainer*>(player)->emptyLineup() == false && monster->getHealth() > 0) && fightOver == false) {
		// get player's monster
		Character* friendly = static_cast<Trainer*>(player)->getMonsterPrompt();

		// rounds of combat until one monster dies
		while (friendly->getHealth() > 0 && monster->getHealth() > 0) {

			// determine who fights first based on speed

			// player's monster attacks first
			if (friendly->getSpeed() >= monster->getSpeed()) {
				cout << "Your monster attacks the enemy monster!" << endl << endl;
				monster->defending(friendly->attacking());

				if (monster->getHealth() > 0) {
					cout << endl << "------------------" << endl;
					cout << "Your monster defends the enemy monster's attack!" << endl << endl;
					friendly->defending(monster->attacking());

					if (friendly->getHealth() <= 0) {
						// there is at least one monster with more than 0 health
						if (!static_cast<Trainer*>(player)->emptyLineup()) {
							cout << "Uh oh! Your monster died... Please choose another to continue combat..." << endl;
							cout << "You may also run from the opponent monster..." << endl;

							int yesNo = -10;
							cout << "Do you want to run?" << endl;
							cout << "	1. Yes" << endl;
							cout << "	2. No" << endl;

							cout << endl << "Run?: ";
							cin >> yesNo;

							// verify a proper option was chosen
							validYesNo(yesNo);

							// player runs
							if (yesNo == 1) {
								fightOver = true;
								break;
							}

							// player doesn't run; select a new monster to replace dead monster
							else if (yesNo == 2) {
								friendly = static_cast<Trainer*>(player)->getMonsterPrompt();
							}
						}

						// all your monsters died
						else
						{
							cout << "Uh oh! Your monster died..." << endl;
							cout << "With an empty lineup, you have failed..." << endl;
							cout << endl << "You lose... Game over..." << endl << endl;
						}
					}
				}

				else {
					cout << "Congratulations! The monster is defeated!" << endl;
					
					// chance to 'drop' a magic lamp (1/3 chance)
					if ((rand() % 3) == 1) {

						// add a magic lamp to the player's inventory
						cout << endl << "Wait... Something drops from the enemy monster..." << endl;
						cout << "You step closer to see what it is... And you reach for the object..." << endl;

						cout << endl << "Congratulations! You just found the Magic Lamp!" << endl;
						cout << "Use the Magic Lamp to find the evil boss..." << endl;
						
						// add the Magic Lamp to the player's inventory
						Item* magicLamp = new MagicLamp();
						static_cast<Trainer*>(player)->addItem(magicLamp);
					}
				}
			}

			// opponent monster attacks first
			else if (monster->getSpeed() > friendly->getSpeed()) {
				cout << "Your monster defends the enemy monster's attack!" << endl << endl;
				friendly->defending(monster->attacking());

				if (friendly->getHealth() > 0) {
					cout << endl << "------------------" << endl << endl;
					cout << "Your monster attacks the enemy monster!" << endl << endl;
					monster->defending(friendly->attacking());

					if (monster->getHealth() <= 0) {
						cout << "Congratulations! The monster is defeated!" << endl;

						// chance to 'drop' a magic lamp (1/3 chance)
						if ((rand() % 3) == 1) 
						{
							// add a magic lamp to the player's inventory
							cout << endl << "Wait... Something drops from the enemy monster..." << endl;
							cout << "You step closer to see what it is... And you reach for the object..." << endl;

							cout << endl << "Congratulations! You just found the Magic Lamp!" << endl;
							cout << "Use the Magic Lamp to find the evil boss..." << endl;

							// add the Magic Lamp to the player's inventory
							Item* magicLamp = new MagicLamp();
							static_cast<Trainer*>(player)->addItem(magicLamp);
						}
					}
				}

				else {
					// there is at least one monster with more than 0 health
					if (!static_cast<Trainer*>(player)->emptyLineup()) 
					{
						cout << "Uh oh! Your monster died... Please choose another to continue combat..." << endl;
						cout << "You may also run from the opponent monster..." << endl;

						int yesNo = -10;
						cout << "Do you want to run?" << endl;
						cout << "	1. Yes" << endl;
						cout << "	2. No" << endl;

						cout << endl << "Run?: ";
						cin >> yesNo;

						// verify a proper option was chosen
						validYesNo(yesNo);

						// player runs
						if (yesNo == 1) {
							fightOver = true;
							break;
						}

						// player doesn't run; select a new monster to replace dead monster
						else if (yesNo == 2) {
							friendly = static_cast<Trainer*>(player)->getMonsterPrompt();
						}
					}

					// all your monsters died
					else
					{
						cout << "Uh oh! Your monster died..." << endl;
						cout << "With an empty lineup, you have failed..." << endl;
						cout << endl << "You lose... Game over..." << endl << endl;
					}
				}
			}
			cout << endl << "----------------------------------------" << endl << endl;
		}
	}
	// free memory for the enemy monster (ONLY if dead)
	if (monster->getHealth() <= 0)
	{
		delete monster;
	}
}

// executes a fight between the player and a (sole) monster (on the board)
void Board::fightWithResult(Character* player, Character* monster, bool& runFromFight) {
	runFromFight = false;
	cout << endl << "----------------------------------------" << endl << endl;

	// fights until either all player's monsters die or the opponent monster dies
	while ((static_cast<Trainer*>(player)->emptyLineup() == false && monster->getHealth() > 0) && runFromFight == false) {
		// get player's monster
		Character* friendly = static_cast<Trainer*>(player)->getMonsterPrompt();

		// rounds of combat until one monster dies
		while (friendly->getHealth() > 0 && monster->getHealth() > 0) {

			// determine who fights first based on speed

			// player's monster attacks first
			if (friendly->getSpeed() >= monster->getSpeed()) {
				cout << "Your monster attacks the enemy monster!" << endl << endl;
				monster->defending(friendly->attacking());

				if (monster->getHealth() > 0) {
					cout << endl << "------------------" << endl;
					cout << "Your monster defends the enemy monster's attack!" << endl << endl;
					friendly->defending(monster->attacking());

					if (friendly->getHealth() <= 0) {
						// there is at least one monster with more than 0 health
						if (!static_cast<Trainer*>(player)->emptyLineup())
						{
							cout << "Uh oh! Your monster died... Please choose another to continue combat..." << endl;
							cout << "You may also run from the opponent monster..." << endl;

							int yesNo = -10;
							cout << "Do you want to run?" << endl;
							cout << "	1. Yes" << endl;
							cout << "	2. No" << endl;

							cout << endl << "Run?: ";
							cin >> yesNo;

							// verify a proper option was chosen
							validYesNo(yesNo);

							// player runs
							if (yesNo == 1) {
								runFromFight = true;
								break;
							}

							// player doesn't run; select a new monster to replace dead monster
							else if (yesNo == 2) {
								friendly = static_cast<Trainer*>(player)->getMonsterPrompt();
							}
						}

						// all your monsters died
						else
						{
							cout << "Uh oh! Your monster died..." << endl;
							cout << "With an empty lineup, you have failed..." << endl;
							cout << endl << "You lose... Game over..." << endl << endl;
						}
					}
				}

				else {
					cout << "Congratulations! The monster is defeated!" << endl;

					// chance to 'drop' a magic lamp (1/3 chance)
					if ((rand() % 3) == 1) {

						// add a magic lamp to the player's inventory
						cout << endl << "Wait... Something drops from the enemy monster..." << endl;
						cout << "You step closer to see what it is... And you reach for the object..." << endl;

						cout << endl << "Congratulations! You just found the Magic Lamp!" << endl;
						cout << "Use the Magic Lamp to find the evil boss..." << endl;

						// add the Magic Lamp to the player's inventory
						Item* magicLamp = new MagicLamp();
						static_cast<Trainer*>(player)->addItem(magicLamp);
					}
				}
			}

			// opponent monster attacks first
			else if (monster->getSpeed() > friendly->getSpeed()) {
				friendly->defending(monster->attacking());

				if (friendly->getHealth() > 0) {
					cout << endl << "------------------" << endl << endl;
					monster->defending(friendly->attacking());

					if (monster->getHealth() <= 0) 
					{
						cout << "Congratulations! The monster is defeated!" << endl;

						// chance to 'drop' a magic lamp (1/3 chance)
						if ((rand() % 3) == 1) {

							// add a magic lamp to the player's inventory
							cout << endl << "Wait... Something drops from the enemy monster..." << endl;
							cout << "You step closer to see what it is... And you reach for the object..." << endl;

							cout << endl << "Congratulations! You just found the Magic Lamp!" << endl;
							cout << "Use the Magic Lamp to find the evil boss..." << endl;

							// add the Magic Lamp to the player's inventory
							Item* magicLamp = new MagicLamp();
							static_cast<Trainer*>(player)->addItem(magicLamp);
						}
					}
				}

				else {
					// there is at least one monster with more than 0 health
					if (!static_cast<Trainer*>(player)->emptyLineup())
					{
						cout << "Uh oh! Your monster died... Please choose another to continue combat..." << endl;
						cout << "You may also run from the opponent monster..." << endl;

						int yesNo = -10;
						cout << "Do you want to run?" << endl;
						cout << "	1. Yes" << endl;
						cout << "	2. No" << endl;

						cout << endl << "Run?: ";
						cin >> yesNo;

						// verify a proper option was chosen
						validYesNo(yesNo);

						// player runs
						if (yesNo == 1) {
							runFromFight = true;
							break;
						}

						// player doesn't run; select a new monster to replace dead monster
						else if (yesNo == 2) {
							friendly = static_cast<Trainer*>(player)->getMonsterPrompt();
						}
					}

					// all your monsters died
					else
					{
						cout << "Uh oh! Your monster died..." << endl;
						cout << "With an empty lineup, you have failed..." << endl;
						cout << endl << "You lose... Game over..." << endl << endl;
					}
				}
			}
			cout << endl << "----------------------------------------" << endl << endl;
		}
	}
	// free memory for the enemy monster (ONLY if dead)
	if (monster->getHealth() <= 0)
	{
		delete monster;
	}
}

// re-point the board space's pointer to the character object that
// will be "placed" on the board at that position
void Board::set(int row, int column, Character* value) {
	board[row][column] = value;
	player = static_cast<Trainer*>(value);
}

// places the trainer on the board
void Board::placeTrainer(Character* trainer) {
	int row = (rand() % dimensions) + 1;
	int col = (rand() % dimensions) + 1;

	// make sure that another object isn't occupying the map's spot
	while (board[row][col] != nullptr) {
		row = (rand() % dimensions);
		col = (rand() % dimensions);
	}

	// place the trainer (player) on the map
	set(row, col, trainer);
}

// place random characters (monsters) on the board
void Board::placeItems() {
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			// random value to determine if an item will be placed on the board
			int x = (rand() % 10) + 1;
			
			// place an item in 10% of locations / spaces
			if (x > 9) {
				Character* monster;

				// random monster (sparty / bieber / wonky / hocuspocus)
				x = (rand() % 4) + 1;

				// sparty
				if (x == 1) {
					monster = new Sparty();
				}

				// bieber
				else if (x == 2) {
					monster = new Bieber();
				}

				// wonky
				else if (x == 3) {
					monster = new Wonky();
				}

				// hocuspocus
				else if (x == 4) {
					monster = new HocusPocus();
				}

				// catch the 'bug'
				else {
					cout << "[BUG] void Board::placeItems()" << endl;
				}

				// place the character / monster on the board
				set(r, c, monster);
			}
		}
	}
}

// returns the monster to the player's right on the board
Character* Board::rightMonster(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// return the monster
	return board[row][col + 1];
}

// checks to see if something occupies the space to the right of the character
bool Board::rightSpaceCheck(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move right
	if (col + 1 < dimensions) {

		// check to see if something is located in the space to the right
		if (board[row][col + 1] != nullptr) {
			return true;
		}

		// the space is NOT occupied by something else
		else if (board[row][col + 1] == nullptr) {
			return false;
		}

		// notify the user of a bug
		else {
			cout << "[BUG] board->rightSpaceCheck(Character* x)..." << endl;
		}
	}

	// the player is at the board's border
	else {
		return true;
	}
}

// moves the character to the right, if "legal"
bool Board::moveRight(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10; 

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move right
	if (col + 1 < dimensions) {
		board[row][col + 1] = x;	// move position
		board[row][col] = nullptr;	// update previous position

		return true;
	}

	else {
		cout << "Uh oh... You can't move to the border. Please try again..." << endl;
		return false;
	}
}

// returns the monster to the player's left on the board
Character* Board::leftMonster(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// return the monster
	return board[row][col - 1];
}

// checks to see if something occupies the space to the left of the character
bool Board::leftSpaceCheck(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move left
	if (col - 1 < dimensions) {

		// check to see if something is located in the space to the left
		if (board[row][col - 1] != nullptr) {
			return true;
		}

		// the space is NOT occupied by something else
		else if (board[row][col - 1] == nullptr) {
			return false;
		}

		// notify the user of a bug
		else {
			cout << "[BUG] board->leftSpaceCheck(Character* x)..." << endl;
		}
	}

	// the player is at the board's border
	else {
		return true;
	}
}

// moves the char to the left, if "legal"
bool Board::moveLeft(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move left
	if (col - 1 < dimensions) {
		board[row][col - 1] = x;	// move position
		board[row][col] = nullptr;	// update previous position

		return true;
	}

	else {
		return false;
	}
}

// returns the monster above the player on the board
Character* Board::upMonster(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// return the monster
	return board[row - 1][col];
}

// checks to see if something occupies the space above the character
bool Board::upSpaceCheck(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move up
	if (row - 1 < dimensions) {

		// check to see if something is located in the above space 
		if (board[row - 1][col] != nullptr) {
			return true;
		}

		// the space is NOT occupied by something else
		else if (board[row - 1][col] == nullptr) {
			return false;
		}

		// notify the user of a bug
		else {
			cout << "[BUG] board->upSpaceCheck(Character* x)..." << endl;
		}
	}

	// the player is at the board's border
	else {
		return true;
	}
}

// move the character up, if "legal"
bool Board::moveUp(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move up
	if (row - 1 < dimensions) {
		board[row - 1][col] = x;	// move position
		board[row][col] = nullptr;	// update previous position

		return true;
	}

	else {
		return false;
	}
}

// returns the monster below the player on the board
Character* Board::downMonster(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// return the monster
	return board[row + 1][col];
}

// checks to see if something occupies the space below the character
bool Board::downSpaceCheck(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move down
	if (row + 1 < dimensions) {

		// check to see if something is located in the below space
		if (board[row + 1][col] != nullptr) {
			return true;
		}

		// the space is NOT occupied by something else
		else if (board[row + 1][col] == nullptr) {
			return false;
		}

		// notify the user of a bug
		else {
			cout << "[BUG] board->upSpaceCheck(Character* x)..." << endl;
		}
	}

	// the player is at the board's border
	else {
		return true;
	}
}

// move the character down, if "legal"
bool Board::moveDown(Character* x) {
	// initialize variables for board coordinates
	int row = -10;
	int col = -10;

	// find the char's spot on the board
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == x) {
				row = r;
				col = c;
			}
		}
	}

	// make sure it's legal to move down
	if (row + 1 < dimensions) {
		board[row + 1][col] = x;	// move position
		board[row][col] = nullptr;	// update previous position

		return true;
	}

	else {
		return false;
	}
}
