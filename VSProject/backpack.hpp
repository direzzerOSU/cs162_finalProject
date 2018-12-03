/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#ifndef BACKPACK_H
#define BACKPACK_H

#include "circularLinkedList.hpp"

class itemQueue;
struct itemNode;
struct Item;
//class Backpack;

// (base class) define items that the player can use (& are stored within the backpack)
struct Item {
	std::string description;

	// attributes
	int health;
	int attack;
	int defense;
	int armor;
	int speed;

	// neutral
	int weapons = 0;
};

//#######################################################
// specific items

// full health potion (restores full health)
struct megaHealingPotion : Item {
	std::string description = "Mega Healing Potion";
	int health = 100;
};

// minor health potion
struct minorHealingPotion : Item {
	std::string description = "Minor Healing Potion";
	int health = 20;
};

// attack increase potion
struct attackPotion : Item {
	std::string description = "Attack Potion";
	int attack = 20;
};

// defense increase potion
struct defensePotion : Item {
	std::string description = "Defense Potion";
	int defense = 20;
};

// attack (decrease) poison
struct attackPoision : Item {
	std::string description = "Attack Poison";
	int attack = -20;
};

// defense (decrease) poison
struct defensePoison : Item {
	std::string description = "Defense Poison";
	int defense = -20;
};

// magic lamp required to fight against the boss
struct MagicLamp : Item {
	std::string description = "Magic Lamp";
};

//######################################################
// backpack (of items)

//// define backpack (as a class)
//class Backpack {
//public:
//	Backpack();
//	~Backpack();
//	//void view();
//private:
//	itemQueue* items = nullptr;
//};
#endif