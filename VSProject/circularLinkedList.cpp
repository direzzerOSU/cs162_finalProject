/*********************************************************************
** Program name: Circular Linked List
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
*********************************************************************/

#include "circularLinkedList.hpp"

// default constructor for a queue of characters
Queue::Queue(Character* value) {
	head->val = value;
}

// default destructor for queue (circular linked list)
Queue::~Queue() {

	// queue (circular linked list) contains 1 node (header)
	if (head->next == nullptr && head->prev == nullptr) {
		if (head != nullptr) {
			delete head;
		}
	}

	// queue (circular linked list) contains >1 node
	else {
		// verify there is at least one node in the queue (circular linked list)
		if (head != nullptr) {
			QueueNode* node = head;
			QueueNode* nodeDelete = node;

			// 'step' one node at a time through the queue (circular linked list) & free memory
			while (node->next != nullptr && node->prev != nullptr && node->next != head && node->prev != head) {
				node = node->next;
				delete nodeDelete;
				nodeDelete = node;
			}
			delete node;
		}
	}
}

// returns whether the queue is empty or not
bool Queue::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// adds a new node to the back of the queue
void Queue::addBack(Character* x) {

	// queue is empty
	if (head == nullptr || head->val == nullptr) {
		QueueNode* node = new QueueNode();
		head = node;
		head->val = x;

		head->next = nullptr;
		head->prev = nullptr;
	}
	
	// queue is not empty
	else if (head != nullptr) {

		// if the queue is 1 node long
		if (head->next == nullptr && head->prev == nullptr) {
			QueueNode* node = new QueueNode();
			head->next = node;
			node->val = x;
			head->prev = node;
		}

		// queue has more than 1 node
		else {
			QueueNode* node = head;

			// find the last node in the circular linked list
			while (node->next != head && node->next != nullptr) {
				if (node->next != head && node->next != nullptr) {
					node = node->next;
				}
			}

			// insert the new node
			QueueNode* newNode = new QueueNode();
			node->next = newNode;
			head->prev = newNode;
			newNode->val = x;
		}
	}
	cout << endl;
	print();
}

// returns the node in the front of the queue
Character* Queue::getFront() {
	// if the list is empty
	if (head == nullptr || head->val == nullptr) {
		cout << "The lineup is empty..." << endl;
		return nullptr;
	}

	return head->val;
}

// removes the front node from the queue
void Queue::removeFront() {
	// list is empty
	if (head == nullptr) {
		// do nothing
	}

	// list has 1 node
	else if (head != nullptr && head->next == nullptr && head->prev == nullptr) {
		delete head;
		head = nullptr;
	}

	// list is longer than 1 node
	else {
		QueueNode* temp = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete temp;
	}
}

// returns the character at a specific position in the queue
Character* Queue::getCharacter(int position) {
	int counter = 0;
	QueueNode* node = head;

	if (head == nullptr) {
		cout << "List is empty..." << endl;
	}

	// return the first character in the lineup
	if (counter == position) {
		return node->val;
	}

	// if there is more than 1 node
	while (node->next != head && node->next != nullptr) {
		// verify the correct node is selected
		if (node->next != head && node->next != nullptr) {
			node = node->next;
			counter++;
		}
		// return the character that was located at the specified position
		if (counter == position) {
			return node->val;
		}
	}

	// (catch the character if missed) verify a character will be returned
	if (node->val != nullptr) {
		return node->val;
	}

	// catch a bug
	else {
		cout << "[BUG] There isn't a character in the entered position..." << endl;
	}
}

// returns the size of the queue
int Queue::size() {
	int counter = 0;

	// if the queue is empty
	if (head == nullptr) {
		return counter;
	}

	// if the queue has at least 1 node
	else if (head != nullptr) {
		counter++;
	}

	QueueNode* node = head;
	// find the total count
	while (node->next != head && node->next != nullptr) {
		if (node->next != head && node->next != nullptr) {
			node = node->next;
			counter++;
		}
	}

	// return the count
	return counter;
}

// print the type of each monster in the player's lineup
void Queue::print()
{
	// lineup is empty
	if (head == nullptr || head->val == nullptr) {
		cout << "Lineup is empty..." << endl;
	}

	// lineup is NOT empty
	else {
		QueueNode* node = head;

		cout << "Lineup: " << endl;
		cout << "     " << node->val->getType() << endl;

		// loop through each monster in the player's lineup
		while (node->next != head && node->next != nullptr) {
			if (node->next != head && node->next != nullptr) {
				node = node->next;
				cout << "     " << node->val->getType() << endl;
			}
		}
	}
	cout << endl;
}


//###########################################################################
// item queue (circular linked list)

// default constructor of an (item) queue for the player's backpack
itemQueue::itemQueue() {
	head = new itemNode();
	head->next = nullptr;
	head->prev = nullptr;
}

// default destructor of an (item) queue for the player's backpack
itemQueue::~itemQueue() {

	// queue (circular linked list) contains 1 node (header)
	if (head->next == nullptr && head->prev == nullptr) {
		if (head != nullptr) {
			delete head;
		}
	}

	// queue (circular linked list) contains >1 node
	else {
		// verify there is at least one node in the queue (circular linked list)
		if (head != nullptr) {
			itemNode* node = head;
			itemNode* nodeDelete = node;

			// 'step' one node at a time through the queue (circular linked list) & free memory
			while (node->next != nullptr && node->prev != nullptr && node->next != head && node->prev != head) {
				node = node->next;
				delete nodeDelete;
				nodeDelete = node;
			}
			delete node;
		}
	}
}

// returns true if the user has the key, which is used to access
// the final 'boss', in the player's backpack
bool itemQueue::hasMagicLamp() {
	if (head != nullptr) {
		itemNode* node = head;

		// the first backpack item is the magic lamp
		if (node->val->description == "Magic Lamp") {
			return true;
		}

		else {
			// loop through the backpack's items
			while (node->next != nullptr && node->next != head) {
				// verify the node's update is legal
				if (node->next != nullptr && node->next != head) {
					node = node->next;
				}

				// check to see if the backpack's item is the magic lamp
				if (node->val->description == "Magic Lamp") {
					return true;
				}				
			}
		}
	}
	// magic lamp is not in the player's backpack
	return false;
}

// returns true if the player's backpack if empty (has no items)
bool itemQueue::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// adds a new item to the player's backpack
void itemQueue::addBack(Item* item) {

	// if backpack is empty
	if (head == nullptr) {
		itemNode* newNode = new itemNode();
		head = newNode;
		head->val = item;
	}

	// backpack is NOT empty
	else {
		itemNode* node = head;

		// find the back of the list
		while (node->next != head && node->next != nullptr) {
			// verify it's 'legal' to step again
			if (node->next != head && node->next != nullptr) {
				node = node->next;
			}
		}

		// add the new item to the back of the itemQueue
		itemNode* newNode = new itemNode();
		node->next = newNode;
		head->prev = newNode;
		newNode->val = item;
	}
}

// returns the first item in the player's backpack (queue/list)
Item* itemQueue::getFront() {
	// if the list is empty
	if (head == nullptr || head->val == nullptr) {
		cout << "The lineup is empty..." << endl;
		return nullptr;
	}

	return head->val;
}

// removes the first item from the player's backpack (or the queue/list)
void itemQueue::removeFront() {
	// list is empty
	if (head == nullptr) {
		// do nothing
	}

	// list has 1 node
	else if (head != nullptr && head->next == nullptr && head->prev == nullptr) {
		delete head;
		head = nullptr;
	}

	// list is longer than 1 node
	else {
		itemNode* temp = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete temp;
	}
}

// returns a specific item from the player's backpack
Item* itemQueue::getItem(int position) {
	int counter = 0;
	itemNode* node = head;

	if (head == nullptr) {
		cout << "List is empty..." << endl;
	}

	// return the first character in the lineup
	if (counter == position) {
		return node->val;
	}

	// if there is more than 1 node
	while (node->next != head && node->next != nullptr) {
		// verify the correct node is selected
		if (node->next != head && node->next != nullptr) {
			node = node->next;
			counter++;
		}
		// return the character that was located at the specified position
		if (counter == position) {
			return node->val;
		}
	}

	// (catch the character if missed) verify a character will be returned
	if (node->val != nullptr) {
		return node->val;
	}

	// catch a bug
	else {
		cout << "[BUG] There isn't a character in the entered position..." << endl;
	}
}

// returns the size of the player's backpack (queue/list)
int itemQueue::size()
{
	int counter = 0;

	// if the queue is empty
	if (head == nullptr) {
		return counter;
	}

	// if the queue has at least 1 node
	else if (head != nullptr) {
		counter++;
	}

	itemNode* node = head;
	// find the total count
	while (node->next != head && node->next != nullptr) {
		if (node->next != head && node->next != nullptr) {
			node = node->next;
			counter++;
		}
	}

	// return the count
	return counter;
}

// print items in the player's backpack
void itemQueue::print()
{
	// lineup is empty
	if (head == nullptr || head->val == nullptr) {
		cout << "Lineup is empty..." << endl;
	}

	// lineup is NOT empty
	else {
		itemNode* node = head;

		cout << "Lineup: " << endl;
		cout << "     " << node->val->description << endl;

		// loop through each monster in the player's lineup
		while (node->next != head && node->next != nullptr) {
			if (node->next != head && node->next != nullptr) {
				node = node->next;
				cout << "     " << node->val->description << endl;
			}
		}
	}
	cout << endl;
}
