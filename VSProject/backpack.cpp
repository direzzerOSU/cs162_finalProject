/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "backpack.hpp"
#include "circularLinkedList.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

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
	if (items == nullptr) 
	{
		items = new itemQueue();
	}
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
	if (items != nullptr)
	{
		items->size();
	}
	else
	{
		cout << "There are no items..." << endl;
	}
}

// print items in the player's backpack
void Backpack::print()
{
	items->print();
}

// random chance for an item to drop (when walking - not after combat)
void Backpack::itemDrop()
{
	// 50% chance that a random item drops
	if (rand() % 2 == 1)
	{
		int val = (rand() % 80) + 1;

		// add megaHealing Potion
		if (val <= 10)
		{
			megaHealingPotion* x = new megaHealingPotion();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add minorHealing Potion
		else if (val <= 20)
		{
			minorHealingPotion* x = new minorHealingPotion();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add attack Potion
		else if (val <= 30)
		{
			attackPotion* x = new attackPotion();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add armor
		else if (val <= 40)
		{
			helmet* x = new helmet();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add attack poison
		else if (val <= 50)
		{
			attackPoison* x = new attackPoison();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add defense poison
		else if (val <= 60)
		{
			defensePoison* x = new defensePoison();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add speed potion
		else if (val <= 70)
		{
			speedPotion* x = new speedPotion();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		// add speed poison
		else if (val <= 80)
		{
			speedPoison* x = new speedPoison();
			cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
			cout << endl << "You have found a " << x->description << "!" << endl;
			addBack(x);
		}

		//// add magic lamp
		//else if (val <= 20)
		//{
		//	MagicLamp* x = new MagicLamp();
		//	cout << "After your player moves, your player finds an item hidden in the dirt..." << endl;
		//	cout << endl << "You have found a " << x->description << "!" << endl;
		//	addBack(x);
		//}
	}
}

// use an item in the player's backpack
void Backpack::useItem(Character* friendly, Item* item)
{
	// use a potion / poison
	friendly->updateStat(item);
}
