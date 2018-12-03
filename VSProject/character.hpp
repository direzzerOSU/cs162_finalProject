/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "circularLinkedList.hpp"

#include<queue>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<vector>
using std::vector;

// forward declaration of class
class Queue;
struct QueueNode;
class itemQueue;
struct itemNode;

// base class for different characters within the game
class Character {
public:
	Character() {};
	~Character() {};
	virtual int attacking() = 0;
	virtual void defending(int) = 0;
	int getHealth();
	std::string getType();
	int roll(int, int);
	int getSpeed();
	int getArmor();
	virtual void printStats() = 0;
 protected:
	std::string charType = "";
	std::string name = "";
	int attack = 0;
	int defense = 0;
	int armor = 0;
	int health = 0;
	int speed = 0;
	int weapons = 0;
};

// derived class for the player's class, Trainer
class Trainer : public Character {
 public:
	 // default constructor to initialize a trainer (with a lineup of pokemon)
	 Trainer() : Character() {
		 charType = "Trainer";
		 selectLineup();
		 createBackpack();
	 }
	 ~Trainer();
	 void createLineup();
	 void selectLineup();
	 bool emptyLineup();
	 void createBackpack();
	 //bool emptyBackpack();
	 int attacking();
	 void defending(int);
	 void printStats();
	 Character* getFrontMonster();
	 Character* getMonster(int);
	 Character* getMonsterPrompt();
	 int getLineupQty();
	 void addLineup(Character*);
 private:
	 int numMonsters = 3;
	 Queue* lineup = nullptr;	// list of pokemon that the trainer has
	 itemQueue* backpack = nullptr;
};

// derived class for the pokemon, Sparty, class
class Sparty : public Character {
 public:
	 // default constructor to initialize a "Sparty", which is a type of Pokemon
	 Sparty() : Character() {
		 charType = "Sparty (the Spartan)";
		 health = 100;
		 armor = 5;
		 hasShield = false;		// Sparty pokemon start with no shield (by default)
		 shield = 0;			// no shield = no additional defense points
		 speed = 3;
		 weapons = 1;
	 }
	 ~Sparty() {};
	 int attacking();
	 void defending(int);
	 void printStats();
 private:
	 bool hasShield = false;
	 int shield = 0;			// indicates whether or not a shield
};

// derived class for the pokemon, Bieber, class
class Bieber : public Character {
public:
	// default constructor to initialize a "Sparty", which is a type of Pokemon
	Bieber() : Character() {
		charType = "Bieber (the Beaver)";
		health = 100;
		armor = 0;
		speed = 5;
		weapons = 1;
	}
	~Bieber() {};
	int attacking();
	void defending(int);
	void printStats();
private:
};

// derived class for the pokemon, Wonky, class
class Wonky : public Character {
public:
	// default constructor to initialize a "Wonky", which is a type of Pokemon
	Wonky() : Character() {
		charType = "Wonky (the Wolverine)";
		health = 100;
		armor = 0;
		speed = 7;
		weapons = 1;
	}
	~Wonky() {};
	int attacking();
	void defending(int);
	void printStats();
private:
};

// derived class for the pokemon, HocusPocus, class
class HocusPocus : public Character {
public:
	// default constructor to initialize a "HocusPocus", which is a type of Pokemon
	HocusPocus() : Character() {
		charType = "HocusPocus (the Magician)";
		health = 100;
		armor = 0;
		speed = 10;
		weapons = 1;
	}
	~HocusPocus() {};
	int attacking();
	void defending(int);
	void printStats();
private:
};

#endif