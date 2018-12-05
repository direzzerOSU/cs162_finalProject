/*********************************************************************
** Program name: Monster Hunting Game
** Author: Ryan DiRezze
** Date: December 4, 2018
** Description: Defines classes and structs to implement the game board.
*********************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include "character.hpp"
#include "menu.hpp"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

class Character;
class Trainer;

class Board {
 public:
	 Board();
	 ~Board();

	 void print();

	 void fight(Character*, Character*);
	 void fightWithResult(Character*, Character*, bool&);

	 void set(int, int, Character*);
	 void placeTrainer(Character*);
	 void placeItems();

	 Character* rightMonster(Character*);
	 bool rightSpaceCheck(Character*);
	 bool moveRight(Character*);
	 Character* leftMonster(Character*);
	 bool leftSpaceCheck(Character*);
	 bool moveLeft(Character*);
	 Character* upMonster(Character*);
	 bool upSpaceCheck(Character*);
	 bool moveUp(Character*);
	 Character* downMonster(Character*);
	 bool downSpaceCheck(Character*);
	 bool moveDown(Character*);
 private:
	 Character*** board;
	 int dimensions = 10;
	 Trainer* player;
}; 
#endif