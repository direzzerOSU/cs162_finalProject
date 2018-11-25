#include "character.hpp"
/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

// Character member functions

// roll n dice with s sides
int Character::roll(int n, int s) {
	int roll = 0;
	
	// rolls n dice & sums the totals (of each die roll)
	for (int k = 0; k < n; k++) {
		roll += (rand() % s) + 1;
	}

	return roll;
}

//###################################################################
// Trainer (Character) member functions

// menu for the user to select all of his/her pokemon (until the lineup is full)
void Trainer::selectLineup() {
	cout << "Please select your pokemon lineup..." << endl;
	cout << "Your pokemon lineup will be used to battle other pokemon and/or trainers." << endl;

	// prompt the menu of possible pokemon to choose from until the user has chosen all his/her pokemon
	while (lineup.size() < numPokemon) {
		cout << "1. Sparty (the Spartan)" << endl;
		cout << "2. Bieber (the Beaver)" << endl;
		cout << "3. Wonky (the Wolverine)" << endl;
		cout << "4. Hocus Pocus (the Magician)" << endl;
	}
}
