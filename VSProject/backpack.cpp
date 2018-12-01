/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "backpack.hpp"
#include "circularLinkedList.hpp"

// default constructor of the backpack
Backpack::Backpack() {
	items = new itemQueue();
}

// default destructor of the backpack
Backpack::~Backpack() {
	delete items;
}

