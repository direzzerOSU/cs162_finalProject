/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "character.hpp"
#include "backpack.hpp"

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;

// forward declaration of class
class Character;
class Queue;
struct QueueNode;
struct Item;
struct itemNode;
class itemQueue;
class Trainer;

// defines a node within the below class (linked list)
struct QueueNode {
	QueueNode* next = nullptr;
	QueueNode* prev = nullptr;
	Character* val = nullptr;
};

// defines a linked list of nodes (above structure)
class Queue {
 public:
	 Queue() {
		 head = new QueueNode();
		 head->next = nullptr;
		 head->prev = nullptr;
	 };
	 Queue(Character*);
	 ~Queue();
	 bool isEmpty();
	 void addBack(Character*);
	 Character* getFront();
	 void removeFront();
	 Character* getCharacter(int);
	 int size();
	 void print();
	 //void reversePrint();
 private:
	 QueueNode* head = nullptr;
};

//#########################################################

// defines a node within the below class (linked list)
struct itemNode {
	itemNode* next = nullptr;
	itemNode* prev = nullptr;
	Item* val = nullptr;
};

// defines a linked list of nodes (above structure)
class itemQueue {
public:
	itemQueue();
	~itemQueue();
	bool hasMagicLamp();
	bool isEmpty();
	void addBack(Item*);
	Item* getFront();
	void removeFront();
	Item* getItem(int);
	int size();
	void print();
	//void reversePrint();
private:
	itemNode* head = nullptr;
};
#endif