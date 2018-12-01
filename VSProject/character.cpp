/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "character.hpp"
#include "inputValidation.hpp"
#include "circularLinkedList.hpp"

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

// returns the pokemon's health
int Character::getHealth() {
	return health;
}

// returns a relative value of speed for determining which pokemon attacks first vs. second (in combat)
int Character::getSpeed() {
	double x = (static_cast<double>(speed) / 10.0) * ((rand() % 100) + 1);

	return static_cast<int>(x);
}

// returns the type of pokemon/character type
std::string Character::getType() {
	return charType;
}

//#########################################
//  Trainer (Character) member functions  #
//#########################################

// default destructor of the Trainer inherited class
Trainer::~Trainer() {
	while (!lineup->isEmpty()) {
		delete lineup->getFront();
		lineup->removeFront();
	}
}

// menu for the user to select all of his/her pokemon (until the lineup is full)
void Trainer::selectLineup() {
	// make sure the lineup container object is available
	if (lineup == nullptr) {
		lineup = new Queue();
	}

	cout << "Please select your pokemon lineup..." << endl;
	cout << "Your pokemon lineup will be used to battle other pokemon and/or trainers." << endl;

	// prompt the menu of possible pokemon to choose from until the user has chosen all his/her pokemon
	while (lineup->size() < numPokemon) {
		cout << "1. Sparty (the Spartan)" << endl;
		cout << "2. Bieber (the Beaver)" << endl;
		cout << "3. Wonky (the Wolverine)" << endl;
		cout << "4. Hocus Pocus (the Magician)" << endl;

		cout << endl << "Selection: ";
		int choice = 9;
		cin >> choice;
		intValidation(choice);

		// ensure the user selects a valid menu option
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "Whoops! You didn't select a valid menu option... Please try again..." << endl;
			cout << endl << "Selection: ";
			cin >> choice;
			intValidation(choice);
		}

		// add sparty to the player's lineup
		if(choice == 1) {
			Character* sparty = new Sparty();
			lineup->addBack(sparty);
		}

		// add bieber to the player's lineup
		else if (choice == 2) {
			Character* bieber = new Bieber();
			lineup->addBack(bieber);
		}

		// add wonky to the player's lineup
		else if (choice == 3) {
			Character* wonky = new Wonky();
			lineup->addBack(wonky);
		}

		// add hocus pocus to the player's lineup
		else if (choice == 4) {
			Character* hocuspocus = new HocusPocus();
			lineup->addBack(hocuspocus);
		}

		// notify the user of a bug within the program
		else {
			cout << "[BUG] Input Validation didn't work as intended with selectLineup()..." << endl;
		}
	}
}

// attack function (should do nothing)
int Trainer::attacking() {
	int x = 0;
	return x;
}

// defending function (should do nothing)
void Trainer::defending(int attackValue) {
}

// print stats
void Trainer::printStats() {
	cout << "Remaining Pokemon: " << lineup->size() << endl;

	// print the type of pokemon for each pokemon in the player's lineup
	for (int n = 0; n < lineup->size(); n++) {
		cout << "	Type: " << lineup->getCharacter(n)->getType() << endl;
		cout << "		Remaining Health: " << lineup->getCharacter(n)->getHealth() << endl;
	}
}

// returns the size of the player's lineup
int Trainer::getLineupQty() {
	return lineup->size();
}


//########################################
//  Sparty (Character) member functions  #
//########################################

// sparty attack
int Sparty::attacking() {
	return roll(weapons, 20);
}

// sparty defend
void Sparty::defending(int attack) {
	health -= (attack - armor - shield);
}

// prints stats
void Sparty::printStats() {
	cout << "Health: " << health << endl;
}

//########################################
//  Bieber (Character) member functions  #
//########################################

// bieber attack
int Bieber::attacking() {
	return roll(weapons, 20);
}

// bieber defend
void Bieber::defending(int attack) {
	health -= (attack - armor);
}

// prints stats
void Bieber::printStats() {
	cout << "Health: " << health << endl;
}

//#######################################
//  Wonky (Character) member functions  #
//#######################################

// wonky attack
int Wonky::attacking() {
	return roll(weapons, 20);
}

// wonky defend
void Wonky::defending(int attack) {
	health -= (attack - armor);
}

// print stats
void Wonky::printStats() {
	cout << "Health: " << health << endl;
}

//############################################
//  HocusPocus (Character) member functions  #
//############################################

// HocusPocus attack
int HocusPocus::attacking() {
	return roll(weapons, 20);
}

// HocusPocus defend
void HocusPocus::defending(int attack) {
	health -= (attack - armor);
}

// print stats
void HocusPocus::printStats() {
	cout << "Health: " << health << endl;
}