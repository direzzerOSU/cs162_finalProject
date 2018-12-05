/*********************************************************************
** Program name: Monster Hunting Game
** Author: Ryan DiRezze
** Date: December 4, 2018
** Description: Defines classes and structs to implement the backpack
   of items.
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
	// default constructor
	Item() {}
	~Item() {}

	// general
	std::string description;
	std::string stat;

	// attributes
	int health = 0;
	int attack = 0;
	int defense = 0;
	int armor = 0;
	int speed = 0;

	// neutral
	int weapons = 0;
};

//#######################################################
// specific items

// full health potion (restores full health)
struct megaHealingPotion : Item 
{
	megaHealingPotion() : Item()
	{
		description = "Mega Healing Potion";
		stat = "Health";
		health = 100;
	}
	~megaHealingPotion() {}
};

// minor health potion
struct minorHealingPotion : Item
{
	minorHealingPotion() : Item()
	{
		description = "Minor Healing Potion";
		stat = "Health";
		health = 20;
	}
	~minorHealingPotion() {}
};

// attack increase potion
struct attackPotion : Item 
{
	attackPotion() : Item()
	{
		description = "Attack Potion";
		stat = "Attack";
		attack = 20;
	}
	~attackPotion() {}
};

// defense increase
struct helmet : Item
{
	helmet() : Item()
	{
		description = "Shield";
		stat = "Armor";
		armor = 20;
	}
	~helmet() {}
};

// attack (decrease) poison
struct attackPoison : Item 
{
	attackPoison() : Item()
	{
		description = "Attack Poison";
		stat = "Attack";
		attack = -20;
	}
	~attackPoison() {}
};

// defense (decrease) poison
struct defensePoison : Item 
{
	defensePoison() : Item()
	{
		description = "Defense Poison";
		stat = "Armor";
		armor = -20;
	}
	~defensePoison() {}
};

// speed potion (increase)
struct speedPotion : Item
{
	speedPotion() : Item()
	{
		std::string description = "Speed Potion";
		std::string stat = "Speed";
		int speed = 20;
	}
	~speedPotion() {}
};

// speed potion (decrease)
struct speedPoison : Item
{
	speedPoison() : Item()
	{
		description = "Speed Poison";
		stat = "Speed";
		speed = -20;
	}
	~speedPoison() {}
};

// magic lamp required to fight against the boss
struct MagicLamp : Item 
{
	MagicLamp() : Item()
	{
		description = "Magic Lamp";
	}
	~MagicLamp() {}
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
	void removeItem(int, Item*);

	// item specific member functions
	void useItem(Character*, Item*);
private:
	itemQueue* items = nullptr;
};
#endif