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
//#include "vld.h"		// visual studio debugging tool (memory leak check)

#include<cstdlib>
#include<ctime>

int main() {
	std::srand(time(0));		// initialize the program's seed for rand()

	bool status = true;
	introMenu(status);		// start/quit the program

	// loop while the game is still active
	while (status) {
		cout << "Game board:" << endl << endl;

		// initialize the board & trainer (player)
		Board* board = new Board();
		Trainer* player = new Trainer();

		// place enemy pokemon on the board
		board->placeItems();

		// place the trainer on the board
		board->placeTrainer(player);

		// print the current board
		board->print();
		cout << endl;

		// ask if the user wants to quit the current game & return to the main menu
		mainMenuReturn(status);

		delete board;
		delete player;
	}

	return 0;
}