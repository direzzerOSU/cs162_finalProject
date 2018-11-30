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
}

// re-point the board space's pointer to the character object that
// will be "placed" on the board at that position
void Board::set(int row, int column, Character* value) {
	board[row][column] = value;
}

// places the trainer on the board
void Board::placeTrainer(Character* trainer) {
	int row = (rand() % dimensions) + 1;
	int col = (rand() % dimensions) + 1;

	// make sure that another object isn't occupying the map's spot
	while (board[row][col] != nullptr) {
		row = (rand() % dimensions) + 1;
		col = (rand() % dimensions) + 1;
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