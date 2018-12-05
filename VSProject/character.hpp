/*********************************************************************
** Program name: Monster Hunting Game
** Author: Ryan DiRezze
** Date: December 4, 2018
** Description: Defines classes and structs to implement the game's
   characters / monsters.
*********************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "circularLinkedList.hpp"
#include "backpack.hpp"
#include "inputValidation.hpp"
#include "circularLinkedList.hpp"
#include "menu.hpp"

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
class itemQueue;
struct itemNode;
struct Item;
class Backpack;
class Queue;
struct QueueNode;

// base class for different characters within the game
class Character {
public:
	Character() {};
	~Character() {};
	virtual int attacking() = 0;
	virtual void defending(int) = 0;
	int getHealth();
	std::string getType();
	void updateStat(Item*);
	int roll(int, int);
	int getSpeed();
	int getArmor();
	virtual void printStats() = 0;
 protected:
	std::string charType = "";
	std::string name = "";
	int attack = 0;
	int attackBonus = 0;
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
		 health = 100;
	 }
	 // default destructor
	 ~Trainer();

	 // game management
	 void gameOver();
	 bool getGameStatus();
	 void drainHealth();

	 // combat
	 int attacking();
	 void defending(int);
	 void printStats();
	 bool fightBoss();

	 // manage monster lineup
	 void createLineup();
	 void selectLineup();
	 void viewLineup();
	 Character* getFrontMonster();
	 Character* getMonster(int);
	 Character* getMonsterPrompt();
	 int getLineupQty();
	 void addLineup(Character*);
	 bool emptyLineup();

	 // manage backpack of items
	 void createBackpack();
	 void viewBackpack();
	 bool emptyBackpack();
	 void useItemPrompt();
	 void useItemMonster(Character*);
	 void addItem(Item*);
	 void randomItem();
 private:
	 int numMonsters = 5;
	 Queue* lineup = nullptr;	// list of pokemon that the trainer has
	 Backpack* backpack = nullptr;
	 bool gameStatus = true;	// true = active; false = game over / ends
};

// derived class for the pokemon, Sparty, class
class Sparty : public Character {
 public:
	 // default constructor to initialize a "Sparty", which is a type of Pokemon
	 Sparty() : Character() {
		 charType = "Sparty (the Spartan)";
		 health = 100;
		 armor = 5;
		 speed = 3;
		 weapons = 1;
	 }
	 ~Sparty() {};
	 int attacking();
	 void defending(int);
	 void printStats();
 private:
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

// Queen Kitty
class QueenKitty : public Character
{
 public:
	 QueenKitty() : Character()
	 {
		 charType = "Queen Kitty";
		 health = 200;
		 armor = 0;
		 speed = 15;
	 }
	 ~QueenKitty() {};
	 int attacking();
	 void defending(int);
	 void printStats();
 private:
}; 
#endif