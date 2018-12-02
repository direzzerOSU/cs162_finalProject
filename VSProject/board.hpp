/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
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

class Board {
 public:
	 Board();
	 ~Board();
	 void print();
	 void fight(Character*, Character*);
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
}; 
#endif