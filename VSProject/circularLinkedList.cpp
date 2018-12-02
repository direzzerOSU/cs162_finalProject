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
void Queue::print() {
	QueueNode* node = head;

	cout << "Lineup: " << endl;
	cout << "     " << node->val->getType() << endl;

	while (node->next != head && node->next != nullptr) {
		if (node->next != head && node->next != nullptr) {
			node = node->next;
			cout << "     " << node->val->getType() << endl;
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

}