/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: 
*********************************************************************/

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "character.hpp"

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;

struct QueueNode {
   QueueNode* next = nullptr;
   QueueNode* prev = nullptr;
   Character* val = nullptr;
};

class Queue {
 public:
    Queue() { head = nullptr; }
    Queue(Character* x);
    ~Queue();
    bool isEmpty();
    void addBack(Character* val);
    Character* getFront();
    void removeFront();
    void printQueue();
    void reversePrint();
    Character* getCharacter(int);
    void shift();
    void clearFront();
	int getQuantity();
 private:
    QueueNode* head = nullptr;
};

#endif
