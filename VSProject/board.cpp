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
	board = new int**[dimensions];	// 10x10 dimensions

	for (int n = 0; n < dimensions; n++) {
		board[n] = new int*[dimensions];

		// reset all pointers to nullptr
		for (int i = 0; i < dimensions; i++) {
			board[n][i] = nullptr;
		}
	}
}

void Board::print() {
	// print the top border of the board
	cout << "-";
	for (int x = 0; x < dimensions; x++) {
		cout << " -";
	}
	cout << " -" << endl;
	// print the board with outside border
	for (int r = 0; r < dimensions; r++) {
		cout << "| ";
		for (int c = 0; c < dimensions; c++) {
			if (board[r][c] == nullptr) {

				cout << "  ";
			}
			else {
				cout << *board[r][c] << " ";
			}
		}
		cout << "|" << endl;
	}
	// print the bottom border of the board
	cout << "-";
	for (int x = 0; x < dimensions; x++) {
		cout << " -";
	}
	cout << " -" << endl;
}

void Board::set(int row, int column, int* value) {
	board[row][column] = value;
}

void Board::placeItems() {
	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			// random value to determine if an item will be placed on the board
			int x = (rand() % 10) + 1;
			
			// place an item in 10% of locations / spaces
			if (x > 9) {
				int* y = new int();
				*y = 1;
				set(r, c, y);
			}
		}
	}
}