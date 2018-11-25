/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<vector>
using std::vector;

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
	std::string charType = 0;
	int attack = 0;
	int defense = 0;
	int armor = 0;
	int health = 0;
};

class Trainer : public Character {
 public:
	 // default constructor to initialize a trainer (with a lineup of pokemon)
	 Trainer() : Character() {
		 charType = "Trainer";
		 selectLineup();
	 }
	 void selectLineup();
 private: 
	 std::vector<Character*> lineup;	// list of pokemon that the trainer has
	 int numPokemon = 3;
};

#endif