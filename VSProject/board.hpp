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
	 void set(int, int, Character*);
	 void placeTrainer(Character*);
	 void placeItems();
 private:
	 Character*** board;
	 int dimensions = 10;
}; 
#endif