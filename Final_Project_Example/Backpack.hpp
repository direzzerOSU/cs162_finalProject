/*****************************************************************************
** Program name: Backpack header
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the header file for the Backpack class.
The Backpack class maintains a circular queue of playerItem structs built as the
user picks up items in CaveEscape. It contains functions for checking if the 
queue is empty, adding a new item, printing the first value in the queue, 
removing the front item, searching for an item, and printing the queue.
*****************************************************************************/

#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Backpack
{
private:
	// playerItem struct contains the item name, next item in queue, and previous item in queue
	struct playerItem
	{
		string itemName;
		playerItem* next;
		playerItem* prev;
		playerItem(string itemIn)
		{
			itemName = itemIn;
			next = nullptr;
			prev = nullptr;
		}
	};

	playerItem* head;

public:
	Backpack();
	~Backpack();
	bool isEmpty();
	void addBack(string);
	string getFront();
	void removeFront();
	void printQueue();
	int itemSearch(string);

};

#endif