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

// adds a monster to the player's lineup
void Character::addLineup(Character* x) {
	lineup->addBack(x);
}

// initialize lineup within the player
void Character::createLineup() {
	lineup = new Queue();
	backpack = new Queue();
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

	cout << "Please select your pokemon lineup.." << endl;
	cout << "Your pokemon lineup will be used to battle other pokemon and/or trainers." << endl << endl;

	// prompt the menu of possible pokemon to choose from until the user has chosen all his/her pokemon
	while (lineup->size() < numMonsters) {
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

		cout << endl;
	}
}

// checks to see if the player's lineup is empty
bool Trainer::emptyLineup() {
	return lineup->isEmpty();
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

// returns the first monster in the player's lineup (of monsters)
Character* Trainer::getFrontMonster() {
	return lineup->getFront();
}

// returns a specific monster in the player's lineup (of monsters)
Character* Trainer::getMonster(int n) {
	return lineup->getCharacter(n);
}

// prompts the user to select a specific monster from his/her lineup
Character* Trainer::getMonsterPrompt() {
	cout << "What monster do you want to use in combat from your lineup?" << endl;
	cout << "(Select the monster's corresponding number)" << endl;

	// print the player's lineup
	cout << endl << "Lineup: " << endl;
	for (int n = 0; n < lineup->size(); n++) {
		cout << "	" << n + 1 << ". " << lineup->getCharacter(n)->getType() << endl;
	}
	cout << endl;

	// acquire user input for the monster selection in combat
	int selection = -10;
	cin >> selection;
	intValidation(selection);

	// ensure the user chose a valid option
	while (selection > lineup->size()) {
		cin >> selection;
		intValidation(selection);
	}

	// return the player's chosen monster (from his/her lineup)
	return lineup->getCharacter(selection - 1);
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
	// rolls two 6-sided dice
	int value = 0;
	value += roll(2, 6);

	attack = value;
	cout << "Attacker Type: " << charType << endl;
	return value;
}

// sparty defend
void Sparty::defending(int attacker) {
	int defender = 0;

	cout << "Defender Type: " << charType << endl;
	cout << "Defender Armor: " << armor << endl;
	cout << "Defender Health Points: " << health << endl;
	cout << "Attacker's Dice Roll: " << attacker << endl;

	// rolls two 6-sided dice
	defender += roll(2, 6);
	defense = defender;
	cout << "Defender's Dice Roll: " << defense << endl;

	int damage = attacker - defense - armor;

	// apply attack & defense for any impact to strength (health)
	if (damage > 0) {
		health -= damage;
		cout << "Total Inflicted Damage: " << damage << endl;
		cout << "Defender's Updated Strength: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Strength: " << health << endl;
	}
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
	// rolls two 6-sided dice
	int value = 0;
	value += roll(2, 6);

	attack = value;
	cout << "Attacker Type: " << charType << endl;
	return value;
}

// bieber defend
void Bieber::defending(int attacker) {
	int defender = 0;

	cout << "Defender Type: " << charType << endl;
	cout << "Defender Armor: " << armor << endl;
	cout << "Defender Health Points: " << health << endl;
	cout << "Attacker's Dice Roll: " << attacker << endl;

	// rolls two 6-sided dice
	defender += roll(2, 6);
	defense = defender;
	cout << "Defender's Dice Roll: " << defense << endl;

	int damage = attacker - defense - armor;

	// apply attack & defense for any impact to strength (health)
	if (damage > 0) {
		health -= damage;
		cout << "Total Inflicted Damage: " << damage << endl;
		cout << "Defender's Updated Strength: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Strength: " << health << endl;
	}
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
	// rolls two 6-sided dice
	int value = 0;
	value += roll(2, 6);

	attack = value;
	cout << "Attacker Type: " << charType << endl;
	return value;
}

// wonky defend
void Wonky::defending(int attacker) {
	int defender = 0;

	cout << "Defender Type: " << charType << endl;
	cout << "Defender Armor: " << armor << endl;
	cout << "Defender Health Points: " << health << endl;
	cout << "Attacker's Dice Roll: " << attacker << endl;

	// rolls two 6-sided dice
	defender += roll(2, 6);
	defense = defender;
	cout << "Defender's Dice Roll: " << defense << endl;

	int damage = attacker - defense - armor;

	// apply attack & defense for any impact to strength (health)
	if (damage > 0) {
		health -= damage;
		cout << "Total Inflicted Damage: " << damage << endl;
		cout << "Defender's Updated Strength: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Strength: " << health << endl;
	}
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
	// rolls two 6-sided dice
	int value = 0;
	value += roll(2, 6);

	attack = value;
	cout << "Attacker Type: " << charType << endl;
	return value;
}

// HocusPocus defend
void HocusPocus::defending(int attacker) {
	int defender = 0;

	cout << "Defender Type: " << charType << endl;
	cout << "Defender Armor: " << armor << endl;
	cout << "Defender Health Points: " << health << endl;
	cout << "Attacker's Dice Roll: " << attacker << endl;

	// rolls two 6-sided dice
	defender += roll(2, 6);
	defense = defender;
	cout << "Defender's Dice Roll: " << defense << endl;

	int damage = attacker - defense - armor;

	// apply attack & defense for any impact to strength (health)
	if (damage > 0) {
		health -= damage;
		cout << "Total Inflicted Damage: " << damage << endl;
		cout << "Defender's Updated Strength: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Strength: " << health << endl;
	}
}

// print stats
void HocusPocus::printStats() {
	cout << "Health: " << health << endl;
}