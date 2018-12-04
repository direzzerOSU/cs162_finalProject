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

// returns true if the backpack is empty (no items)
bool Backpack::emptyBackpack()
{
	return items->isEmpty();
}

// returns true if the user has the key, which is used to access
// the final 'boss', in the player's backpack
bool Backpack::hasMagicLamp()
{
	return items->hasMagicLamp();
}

// returns true if the player's backpack if empty (has no items)
bool Backpack::isEmpty()
{
	return items->isEmpty();
}

// adds a new item to the player's backpack
void Backpack::addBack(Item* item)
{
	items->addBack(item);
}

// returns the first item in the player's backpack (queue/list)
Item* Backpack::getFront()
{
	return items->getFront();
}

// removes the first item from the player's backpack (or the queue/list)
void Backpack::removeFront()
{
	items->removeFront();
}

// returns a specific item from the player's backpack
Item* Backpack::getItem(int position)
{
	items->getItem(position);
}

// returns the size of the player's backpack (queue/list)
int Backpack::size()
{
	items->size();
}

// print items in the player's backpack
void Backpack::print()
{
	items->print();
}

// use an item in the player's backpack
void Backpack::useItem(Character* friendly, Item* item)
{
	// use a magic lamp
	if (item->description == "Magic Lamp") {
		cout << "You rub the magic lamp, hoping something will happen..." << endl;
		cout << "The next thing your character knows, he is standing in front of the evil boss..." << endl;

		cout << endl << "You must use your monsters to fight against the evil boss, whose name is, Queen Kitty!" << endl;

		// begin combat against Queen Kitty
	}

	// use a potion / poison
	else {
		//friendly->
	}

}
