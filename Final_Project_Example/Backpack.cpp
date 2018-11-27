/*****************************************************************************
** Program name: Backpack implementation
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the implementation file for the Backpack class.
The Backpack class maintains a circular queue of playerItem structs built as the
user picks up items in CaveEscape. It contains functions for checking if the
queue is empty, adding a new item, printing the first value in the queue,
removing the front item, searching for an item, and printing the queue.
*****************************************************************************/

#include "Backpack.hpp"

// Constructor, defaults head to nullptr
Backpack::Backpack()
{
	head = nullptr;
}

// isEmpty checks if head is currently set to nullptr (empty) and return true or false
bool Backpack::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// addBack creates a new node
void Backpack::addBack(string newItem)
{
	// dynamically allocate a new node
	playerItem* temp = new playerItem(newItem);

	// first node
	if (isEmpty())
	{
		temp->next = temp;
		temp->prev = temp;
		head = temp;
	}
	// not first node
	else
	{
		temp->next = head;
		temp->prev = head->prev;
		head->prev->next = temp;
		head->prev = temp;
	}
}

// return the value in the head node
string Backpack::getFront()
{
	return (head->itemName);
}

// removes the front node
void Backpack::removeFront()
{
	playerItem* temp;

	// final node, sets head to nullptr before deleting
	if (head == head->next)
	{
		temp = head;
		head = nullptr;
		delete temp;
	}
	// not the last node
	else
	{
		temp = head;
		head = head->next;
		temp->prev->next = head;
		head->prev = temp->prev;

		delete temp;
	}
}

// loop through the queue and print values
void Backpack::printQueue()
{
	playerItem* temp = head;
	do {
		cout << temp->itemName << " ";
		temp = temp->next;
	} while (temp != head);
	cout << "\n";
}

// search for a string and return the number of times it is found
int Backpack::itemSearch(string itemCheck)
{
	playerItem* temp = head;
	int count = 0;

	do {
		if (temp->itemName == itemCheck)
		{
			count++;
		}
		temp = temp->next;
	} while (temp != head);

	return count;
}

// deconstructor that deletes any remaining nodes
Backpack::~Backpack()
{
	playerItem* stop = head;
	playerItem* follower;

	if (!isEmpty())
	{
		do {
			follower = head;
			head = head->next;
			delete follower;
		} while (head != stop);

	}
}