/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "board.hpp"
#include "inputValidation.hpp"
#include "menu.hpp"
#include "character.hpp"

#include<cstdlib>
#include<ctime>

int main() {
	std::srand(time(0));		// initialize the program's seed for rand()

	bool status = true;
	introMenu(status);		// start/quit the program

	// loop while the game is still active
	while (status) {
		cout << "Game board:" << endl << endl;

		Board* board = new Board();

		board->placeItems();
		board->print();

		delete board;
		mainMenuReturn(status);
	}

	return 0;
}