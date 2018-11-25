/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>

class Character {
public:
	Character() {};
	virtual int attacking() = 0;
	virtual void defending(int) = 0;
	virtual int getStrength() = 0;
	virtual std::string getType() = 0;
	int roll(int, int);
	virtual void printStats() = 0;
	virtual ~Character() {};
protected:
	std::string charType;
	int attack = 0;
	int defense = 0;
	int armor = 0;
	int health = 0;
};
#endif