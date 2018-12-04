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
#include "character.hpp"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class itemQueue;
struct itemNode;
struct Item;
class Backpack;
class Character;

// (base class) define items that the player can use (& are stored within the backpack)
struct Item {
	// general
	std::string description = "Item";
	std::string stat;

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
	std::string stat = "Health";
	int health = 100;
};

// minor health potion
struct minorHealingPotion : Item {
	std::string description = "Minor Healing Potion";
	std::string stat = "Health";
	int health = 20;
};

// attack increase potion
struct attackPotion : Item {
	std::string description = "Attack Potion";
	std::string stat = "Attack";
	int attack = 20;
};

// defense increase potion
struct armor : Item {
	std::string description = "Shield";
	std::string stat = "Armor";
	int armor = 20;
};

// attack (decrease) poison
struct attackPoison : Item {
	std::string description = "Attack Poison";
	std::string stat = "Attack";
	int attack = -20;
};

// defense (decrease) poison
struct defensePoison : Item {
	std::string description = "Defense Poison";
	std::string stat = "Armor";
	int armor = -20;
};

// speed potion (increase)
struct speedPotion : Item
{
	std::string description = "Speed Potion";
	std::string stat = "Speed";
	int speed = 20;
};

// speed potion (decrease)
struct speedPoison : Item
{
	std::string description = "Speed Poison";
	std::string stat = "Speed";
	int speed = -20;
};

// magic lamp required to fight against the boss
struct MagicLamp : public Item {
	description = "Magic Lamp";
};


//######################################################
// backpack (of items)

// define backpack (as a class)
class Backpack {
public:
	// default constructor & desctructor
	Backpack();
	~Backpack();

	// backpack member functions, utilizing itemQueue member functions
	bool emptyBackpack();
	bool hasMagicLamp();
	bool isEmpty();
	void addBack(Item*);
	Item* getFront();
	void removeFront();
	Item* getItem(int);
	int size();
	void print();
	void itemDrop();

	// item specific member functions
	void useItem(Character*, Item*);
private:
	itemQueue* items = nullptr;
};
#endif