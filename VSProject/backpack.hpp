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
class Backpack;

// (base class) define items that the player can use (& are stored within the backpack)
struct Item {
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
struct fullHealthPotion : Item {
	int health = 100;
};

// minor health potion
struct minorHealthPotion : Item {
	int health = 20;
};

// attack increase potion
struct attackPotion : Item {
	int attack = 20;
};

// defense increase potion
struct defensePotion : Item {
	int defense = 20;
};

// attack (decrease) poison
struct attackPoision : Item {
	int attack = -20;
};

// defense (decrease) poison
struct defensePoison : Item {
	int defense = -20;
};

//######################################################
// backpack (of items)

// define backpack (as a class)
class Backpack {
public:
	Backpack();
	~Backpack();
	//void view();
private:
	itemQueue* items = nullptr;
};
#endif