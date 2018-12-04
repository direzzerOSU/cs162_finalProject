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
#include "circularLinkedList.hpp"
#include "backpack.hpp"

// forward declarations of classes & structs
struct QueueNode;
class Queue;
struct itemNode;
class itemQueue;
class Character;
class Backpack;
struct Item;

// Visual Studio memory tool
//#include "vld.h"		// visual studio debugging tool (memory leak check)

#include<cstdlib>
#include<ctime>

int main() {
	std::srand(std::time(0));		// initialize the program's seed for rand()

	bool status = true;

	// loop while the game is still active
	while (status) {
		cout << endl;
		introMenu(status);		// start/quit the program

		// catch a break if the user wants to quit
		if (status == false) 
		{
			break;
		}

		// initialize the board & trainer (player)
		Board* board = new Board();
		Character* player = new Trainer();

		cout << "Test1" << endl;
		Item* x = new MagicLamp();
		cout << "Test2" << endl;
		static_cast<Trainer*>(player)->addItem(x);
		cout << "Test3" << endl;
		// verify the user is ready to begin the game before starting...
		cout << endl << "Are you ready to begin gameplay?" << endl;
		int input = -10;
		yesOrNo(input);

		// loop until the player is ready to begin
		while (input != 1) {
			cout << endl << "Are you ready to begin gameplay now?" << endl;
			yesOrNo(input);
			validYesNo(input);
			cout << endl;
		}

		// place enemy pokemon on the board
		board->placeItems();

		// place the trainer on the board
		board->placeTrainer(player);

		// standard gameplay
		while (static_cast<Trainer*>(player)->getGameStatus()) {
			// print the current board
			board->print();
			cout << endl;

			turnMenu(board, player);

			cout << endl;
		}

		// ask if the user wants to quit the current game & return to the main menu
		mainMenuReturn(status);

		delete board;
		delete player;
	}

	return 0;
}