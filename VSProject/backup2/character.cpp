/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "character.hpp"

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

// returns the number of armor points (for defense)
int Character::getArmor() {
	return armor;
}

// returns the type of pokemon/character type
std::string Character::getType() {
	return charType;
}

// updates the character's (monster's) stat(s) based on an item (potion/poison)
void Character::updateStat(Item* item)
{
	// health related item
	if (item->stat == "Health")
	{
		health += item->health;

		// notify the user
		if (item->health > 0)
		{
			cout << "You heal your " << charType << " for " << item->health << " points..." << endl;
		}

		else if (item->health < 0)
		{
			cout << "Your " << charType << "'s health decreases by " << item->health << " points..." << endl;
		}

		else
		{
			cout << "The " << item->description << " had no impact on your " << charType << "..." << endl;
		}
	}

	// attack related item
	else if (item->stat == "Attack")
	{
		attackBonus = item->attack;

		// notify the user
		if (item->attack > 0)
		{
			cout << "You increase your " << charType << "'s attack by " << item->attack << " points..." << endl;
		}

		else if (item->health < 0)
		{
			cout << "You decrease your " << charType << "'s attack by " << item->attack << " points..." << endl;
		}

		else
		{
			cout << "The " << item->description << " had no impact on your " << charType << "..." << endl;
		}
	}

	// defense related item
	else if (item->stat == "Armor")
	{
		armor += item->armor;

		// notify the user
		if (item->armor > 0)
		{
			cout << "You increase your " << charType << "'s armor by " << item->armor << " points..." << endl;
		}

		else if (item->health < 0)
		{
			cout << "You decrease your " << charType << "'s armor by " << item->armor << " points..." << endl;
		}

		else
		{
			cout << "The " << item->description << " had no impact on your " << charType << "..." << endl;
		}
	}

	// speed related item
	else if (item->stat == "Speed")
	{
		speed += item->speed;

		// notify the user
		if (item->speed > 0)
		{
			cout << "You increase your " << charType << "'s speed by " << item->speed << " points..." << endl;
		}

		else if (item->speed < 0)
		{
			cout << "You decrease your " << charType << "'s speed by " << item->speed << " points..." << endl;
		}

		else
		{
			cout << "The " << item->description << " had no impact on your " << charType << "..." << endl;
		}
	}

	// catch others
	else
	{
		// do nothing
	}
}


//#########################################
//  Trainer (Character) member functions  #
//#########################################

// default destructor of the Trainer inherited class
Trainer::~Trainer() 
{
	delete lineup;
	delete backpack;
}

// ends the game
void Trainer::gameOver()
{
	gameStatus = false;
}

// returns the current game status (true = active; false = over)
bool Trainer::getGameStatus()
{
	// if player dies, then the game is over
	if (health <= 0) 
	{
		cout << endl << "After your last step, you realize that you've been exposed to the toxic air for too long..." << endl;
		cout << "You fall to the ground and suffocate to death from the toxic air..." << endl;
		cout << endl << "Game over..." << endl << endl;
		gameStatus = false;
	}
	return gameStatus;
}

// decreases the trainer's health with every step - the player must defeat the boss before
// the player dies or else the player will lose
void Trainer::drainHealth()
{
	cout << endl << endl << "Your health drains..." << endl << endl;
	health -= 10;
}

// initialize lineup within the player
void Trainer::createLineup() {
	lineup = new Queue();
}

// menu for the user to select all of his/her pokemon (until the lineup is full)
void Trainer::selectLineup() {
	// make sure the lineup container object is available
	if (lineup == nullptr) {
		lineup = new Queue();
	}

	cout << "Please select your lineup of monsters for combat.." << endl;
	cout << "Your lineup will be used to battle enemy monsters and the enemy boss." << endl << endl;

	// prompt the menu of possible pokemon to choose from until the user has chosen all his/her pokemon
	while (lineup->size() < numMonsters) {

		cout << "1. Sparty (the Spartan)" << endl;
		cout << "	Health: 100" << endl;
		cout << "	Armor:  5" << endl;
		cout << "	Speed:  3" << endl;

		cout << "2. Bieber (the Beaver)" << endl;
		cout << "	Health: 100" << endl;
		cout << "	Armor:  0" << endl;
		cout << "	Speed:  5" << endl;

		cout << "3. Wonky (the Wolverine)" << endl;
		cout << "	Health: 100" << endl;
		cout << "	Armor:  0" << endl;
		cout << "	Speed:  7" << endl;

		cout << "4. Hocus Pocus (the Magician)" << endl;
		cout << "	Health: 100" << endl;
		cout << "	Armor:  0" << endl;
		cout << "	Speed:  10" << endl;

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

// prints the player's lineup of monsters (by type)
void Trainer::viewLineup()
{
	lineup->print();
}

// checks to see if the player's lineup is empty
bool Trainer::emptyLineup() {
	return lineup->isEmpty();
}

// initializes & creates a backpack for the player's items
void Trainer::createBackpack() {
	backpack = new Backpack();
}

// views items in the player's backpack
void Trainer::viewBackpack()
{
	backpack->print();
}

// returns true if the backpack is empty
bool Trainer::emptyBackpack()
{
	return backpack->isEmpty();
}

// uses an item in the player's backpack
void Trainer::useItemPrompt()
{
	cout << "You open up your backpack and examine all your items..." << endl;

	// list all items in the player's backpack
	cout << endl << "Items in backpack:" << endl;
	for (int k = 0; k < backpack->size(); k++) {
		cout << "	" << k+1 << ") " << backpack->getItem(k)->description << endl;
	}

	// user chooses an item to use
	cout << endl << "What item would you like to use? (Input the item's corresponding number)" << endl;
	cout << "Please input 0 if you would like to return to the game menu..." << endl;
	int selection = -10;
	cout << "Selection: ";
	cin >> selection;
	intValidation(selection);

	// ensure the choice is valid
	while (selection > backpack->size()) {
		cout << "Whoops! That's not a valid choice... Please try again..." << endl;
		cout << "Selection: ";
		cin >> selection;
		intValidation(selection);
	}

	// select a monster to use the item on
	if (backpack->getItem(selection - 1)->description != "Magic Lamp") 
	{
		// print player's lineup
		cout << "What monster (in your lineup) would you like to use the item on?" << endl << endl;
		lineup->print();

		// use item & update the player's monster's stats
		int monster = -10;
		cout << "Please choose the monster that you'd like to use your item on..." << endl;
		cout << "Selection: ";
		cin >> monster;
		intValidation(monster);

		// ensure a valid option is chosen
		while (monster > lineup->size())
		{
			cout << "Whoops! You didn't choose a valid option... Please try again..." << endl;
			cout << "Selection: ";
			cin >> monster;
			intValidation(monster);
		}

		// use an item
		backpack->useItem(lineup->getCharacter(monster), backpack->getItem(selection));
	}

	// magic lamp is chosen
	else if (backpack->getItem(selection - 1)->description == "Magic Lamp")
	{
		cout << "You rub the magic lamp, hoping something will happen..." << endl;
		cout << "The next thing your character knows, he is standing in front of the evil boss..." << endl;

		cout << endl << "You must use your monsters to fight against the evil boss, whose name is, Queen Kitty!" << endl;

		cout << endl << "Are you ready to fight Queen Kitty?..." << endl;
		int selection = -10;
		yesOrNo(selection);
		validYesNo(selection);

		// do not begin the fight until the player is ready
		while (selection != 1)
		{
			cout << endl << "Are you ready to fight Queen Kitty?" << endl;
			yesOrNo(selection);
			validYesNo(selection);
		}

		// begin combat against Queen Kitty
		if (selection == 1)
		{
			bool result = fightBoss();

			// celebrate the victory
			if (result)
			{
				cout << "Congratulations! You won!... You defeated the evil Queen Kitty!" << endl;
			}

			// you lost
			else if (!result)
			{
				cout << "Oh no! You have been defeated!... Queen Kitty will continue to wreak havoc on humanity..." << endl;
			}

			// game over only if all of your monsters died
			if (lineup->isEmpty())
			{
				gameOver();
			}
		}
	}

	// return to the game menu
	else
	{
		// do nothing
	}
}

// use an item on a specific monster
void Trainer::useItemMonster(Character* friendly)
{
	cout << "You open up your backpack and examine all your items..." << endl;

	// list all items in the player's backpack
	cout << endl << "Items in backpack:" << endl;
	for (int k = 0; k < backpack->size(); k++) {
		cout << "	" << k + 1 << ") " << backpack->getItem(k)->description << endl;
	}

	// user chooses an item to use
	cout << "What item would you like to use? (Input the item's corresponding number)" << endl;
	int selection = -10;
	cout << "Selection: ";
	cin >> selection;
	intValidation(selection);

	// ensure the choice is valid
	while (selection > backpack->size()) {
		cout << "Whoops! That's not a valid choice... Please try again..." << endl;
		cout << "Selection: ";
		cin >> selection;
		intValidation(selection);
	}

	// use an item
	backpack->useItem(friendly, backpack->getItem(selection));
}

// adds an item to the player's backpack
void Trainer::addItem(Item* item)
{
	backpack->addBack(item);
}

// chance that a random item drops
void Trainer::randomItem()
{
	// 50% chance that a random item drops
	// of available items, MagicLamp has 20% probability; all others have 10% chance
	backpack->itemDrop();
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

// fight Queen Kitty
bool Trainer::fightBoss()
{
	bool status = true;
	QueenKitty* monster = new QueenKitty();

	cout << endl << "----------------------------------------" << endl << endl;

	// fights until either all player's monsters die or the opponent monster dies
	while (emptyLineup() == false && monster->getHealth() > 0 && status == true) {
		// get player's monster
		Character* friendly = getMonsterPrompt();

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
						if (!lineup->isEmpty()) {
							cout << "Uh oh! Your monster died... Please choose another to continue combat..." << endl;
							cout << endl << "You may also run from the opponent monster..." << endl;

							int yesNo = -10;
							cout << endl << "Do you want to run?" << endl;

							// verify a proper option was chosen
							yesOrNo(yesNo);

							// loop until a correct choice is made
							while (yesNo != 1 && yesNo != 2)
							{
								validYesNo(yesNo);
							}

							// player runs
							if (yesNo == 1) {
								cout << endl << "You decide to run... Queen Kitty will continue to wreak havoc!" << endl;
								status = false;
								return false;
							}

							// player doesn't run; select a new monster to replace dead monster
							else if (yesNo == 2) {
								friendly = getMonsterPrompt();
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
					cout << "Congratulations! You defeated Queen Kitty!" << endl;
					status = false;
					delete monster;
					gameOver();
					return true;
				}
			}

			// opponent monster attacks first
			else if (monster->getSpeed() > friendly->getSpeed()) {
				cout << "Your monster defends the enemy monster's attack!" << endl << endl;
				friendly->defending(monster->attacking());

				if (friendly->getHealth() > 0) {
					cout << "Your monster attacks the enemy monster!" << endl << endl;
					monster->defending(friendly->attacking());

					// queen kitty is dead
					if (monster->getHealth() <= 0) {

						// congratulatory note to the hero (winner)
						cout << "Congratulations! You defeated Queen Kitty!" << endl;
						cout << endl << "..." << endl;
						cout << endl << "All of a sudden you feel a stong gust of wind and......" << endl;
						cout << endl << "You snap back to consciousness!" << endl;
						cout << endl << "You realize that you're back where you were before rubbing the Magic Lamp..." << endl;
						
						cout << endl << "Queen Kitty is now defeated, and you can now rest at peace knowing\n";
						cout << "that she has been laid to rest for good..." << endl;
						cout << "Excellent work, hero! Because of your fearsome lineup of monsters and your\n";
						cout << "relentless determination, you have saved the world from Queen Kitty, who \n";
						cout << "had put a shroud of darkness over the world for your lifetime..." << endl;

						cout << endl << "Game over..." << endl << endl;
						
						status = false;
						delete monster;
						gameOver();
						return true;
					}
				}

				else {
					// there is at least one monster with more than 0 health
					if (!lineup->isEmpty()) {
						cout << "Uh oh! Your monster died... Please choose another to continue combat..." << endl;
						cout << endl << "You may also run from the opponent monster..." << endl;

						int yesNo = -10;
						cout << endl << "Do you want to run?" << endl;
						cout << "	1. Yes" << endl;
						cout << "	2. No" << endl;

						cout << endl << "Run?: ";
						cin >> yesNo;

						// loop until a correct choice is made
						while (yesNo != 1 && yesNo != 2)
						{
							validYesNo(yesNo);
						}

						// player runs
						if (yesNo == 1) {
							status = false;
							return false;
						}

						// player doesn't run; select a new monster to replace dead monster
						else if (yesNo == 2) {
							friendly = getMonsterPrompt();
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
		cout << "		Remaining Health: " << lineup->getCharacter(n)->getHealth() << endl;
	}
	cout << endl;

	// acquire user input for the monster selection in combat
	int selection = -10;
	cout << "Monster: ";
	cin >> selection;
	intValidation(selection);

	// ensure the user chose a valid option
	while (selection > lineup->size()) {
		cout << endl << "Whoops! You didn't choose a valid monster from your lineup... Please try again..." << endl;
		cout << "Selection: ";
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

// adds a monster to the player's lineup
void Trainer::addLineup(Character* x) {
	lineup->addBack(x);
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
		cout << "Defender's Updated Health: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Health: " << health << endl;
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
		cout << "Defender's Updated Health: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Health: " << health << endl;
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
		cout << "Defender's Updated Health: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Health: " << health << endl;
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
		cout << "Defender's Updated Health: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Health: " << health << endl;
	}
}

// print stats
void HocusPocus::printStats() {
	cout << "Health: " << health << endl;
}

//#############################################
//  Queen Kitty (Character) member functions  #
//#############################################

// returns the attack value of Queen Kitty's attack
int QueenKitty::attacking()
{
	// rolls two 6-sided dice
	int value = 0;
	value += roll(2, 6);

	attack = value;
	cout << "Attacker Type: " << charType << endl;
	return value;
}

void QueenKitty::defending(int attacker)
{
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
		cout << "Defender's Updated Health: " << health << endl;

		if (health <= 0) {
			cout << endl << getType() << " has been defeated!" << endl;
		}
	}
	else {
		// do nothing - the char defended against the attack
		cout << "Total Inflicted Damage: 0" << endl;
		cout << "Defender's Updated Health: " << health << endl;
	}
}

// prints character related stats
void QueenKitty::printStats()
{
	cout << "Health: " << health << endl;
}
