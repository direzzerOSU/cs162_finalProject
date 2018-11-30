/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Implements various functions within the QueueNode
   struct and Queue class required to implement a program that
   uses circular linked lists
*********************************************************************/

#include "CircularLinkedList.hpp"

// initializes a new list with a specific value for the first node
Queue::Queue(Character* x) {
   head = new QueueNode();
   head->val = x;
}

// Queue class destructor
Queue::~Queue() {

   if(head == nullptr) {
      // do nothing
   }
   
   // free memory of all nodes within the linked list
   else {
      QueueNode* node = head;
      QueueNode* nodeDelete = head;
      
      // iterate through the list
//      while(nodeDelete != nullptr) {
//         node = node->next;
//         delete nodeDelete->val;
//         delete nodeDelete;
//         nodeDelete = node;
//      }

      while(node->next != nullptr) {
         node = node->next;
         if(nodeDelete->val != nullptr) {
            delete nodeDelete->val;
         }
         if(nodeDelete != nullptr) {
            delete nodeDelete;
         }
         nodeDelete = node;
      }
      
      if(nodeDelete->val != nullptr) {
         delete nodeDelete->val;
      }
      if(nodeDelete != nullptr) {
         delete nodeDelete;
      }
   }
}

// indicates whether the list is empty or not
bool Queue::isEmpty() {
   if(head == nullptr) {
      return true;
   }
   else {
      return false;
   }
}

// adds a new node to the back of the list
void Queue::addBack(Character* value) {

   // if the list is empty
   if(head == nullptr) {
      head = new QueueNode();
      head->val = value;
   }

   // if there's only 1 character/fighter in the list
   else if(head->next == nullptr && head->prev == nullptr && head->next != head && head->prev != head) {
      QueueNode* temp = new QueueNode();
      temp->val = value;
      head->next = temp;
      head->prev = temp;
      temp->next = head;
      temp->prev = head;
   }

   // if there is >1 character/fighter in the list
   else {
      QueueNode* node = head;

      // finds the last node in the list
      while(node->next != nullptr && node->next != head) {
         node = node->next;
      }

      // create new "spot" in the list
      QueueNode* temp = new QueueNode();  // to add a new char
      temp->val = value;

      // update the end of the list
      node->next = temp;
      temp->prev = node;
      
      // update the beginning of the list
      temp->next = head;
      head->prev = temp;
   }
}

// returns a pointer to the character
Character* Queue::getFront() {
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
      return head->val;    // added
   }
   else {
      return head->val;
   }
}

// print queue
void Queue::printQueue() {
   // handle an empty list
   if(head == nullptr) {
//      cout << "There are no fighters to print..." << endl;
   }
   // handle a list with 1+ fighters
   else {
      cout << "Fighers: ";

      // handle a list with fighterCount == 1
      if((head->prev == nullptr && head->next == nullptr) || (head->prev == head && head->next == head)) {
         cout << head->val->getType() << endl;
      }

      // handle a list with fighterCount > 1
      else {
         QueueNode* node = head;
         cout << node->val->getType() << " ";
         while(node->next != nullptr && node->next != head) {
            node = node->next;
            cout << node->val->getType() << " ";
         }
      }
   }
}


// reverse print queue
void Queue::reversePrint() {
   // handle an empty list
   if(head == nullptr) {
//      cout << "There are no fighters to print..." << endl;
   }
   // handle a list with 1+ fighters
   else {
      cout << "Fighers: ";

      // handle a list with fighterCount == 1
      if(head->prev == nullptr && head->next == nullptr) {
         cout << head->val->getType() << endl;
      }

      // handle a list with fighterCount > 1
      else {
         QueueNode* node = head->prev;
         cout << node->val->getType() << " ";
         while(node->prev != nullptr && node->prev != head->prev) {
            node = node->prev;
            cout << node->val->getType() << " ";
         }
      }
   }
}

// returns the character at a particular position in the list
Character* Queue::getCharacter(int x) {
   
   // list is empty
   if(head == nullptr) {
      cout << "There aren't any characters on this team..." << endl;
      return head->val;    // added
   }

   QueueNode* node = head;
   int counter = 0;

   // list is NOT empty
   while(node != nullptr) {
      if(counter == x) {
         return node->val;
      }
      node = node->next;
      counter++;
   }
   return node->val;    // added
   cout << "Uh oh! There are only " << x+1 << " players on the team, beginning at position 0..." << endl;
}

// shifts the lineup & moves the next character (fighter) to the start of the
// "lineup" / list -- this is used when a fight completes between two fighters
void Queue::shift() {
   cout << "Shifting lineup..." << endl << endl;

   // if the list has 1 character/fighter
   if((head->next == nullptr && head->prev == nullptr) || (head->next == head && head->prev == head)) {
      // do nothing -- cannot shift with only 1 fighter
   }

   // if the list has >1 character/fighter
   else if(head->next != nullptr && head->prev != nullptr && head->next != head && head->prev != head) {
      QueueNode* nodePrev = head;
      QueueNode* nodeNext = head->next;
      head = nodeNext;

      // if the list has 2 characters/fighters
      if(nodeNext == head->prev) {
         head->prev = nodePrev;
         head->next = nodePrev;
      }

      // if the list has >2 characters/fighters
      else {
         // update the 'head' node & update next/prev nodes
         nodeNext = nodeNext->next;
         head->prev = nodePrev;
         head->next = nodeNext;
      }
   }
}

// removes the front node/character from the linked list
void Queue::removeFront() {

   // list is empty
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
   }

   // list is NOT empty
   else {
      
      // there's only 1 character/fighter in the list
      if(head->next == nullptr && head->prev == nullptr) {
         head = nullptr;
//         cout << "List is now empty..." << endl;
      }

      // there's >1 character/fighter in the list
      else {
         QueueNode* node = head;
         QueueNode* prev = head->prev;
         QueueNode* next = head->next;

         next->prev = prev;
         prev->next = next;

         // update the head node to reflect a single element in the list
         if(head->next == head->prev) {
            head = next;
            head->next = nullptr;
            head->prev = nullptr;
         }
         else {
            head->next = nullptr;
            head->prev = nullptr;
            head = next;
         }
      }
   }
}

// deletes the first node
void Queue::clearFront() {
   // list is empty
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
   }

   // list is NOT empty
   else {
      
      // there's only 1 character/fighter in the list
      if(head->next == nullptr && head->prev == nullptr) {
         delete head->val;
         delete head;
         head = nullptr;
//         cout << "List is now empty..." << endl;
      }

      // there's >1 character/fighter in the list
      else {
         QueueNode* node = head;
         QueueNode* prev = head->prev;
         QueueNode* next = head->next;

         next->prev = prev;
         prev->next = next;

         // update the head node to reflect a single element in the list
         if(head->next == head->prev) {
            delete head->val;
            delete head;
            head = next;
            head->next = nullptr;
            head->prev = nullptr;
         }
         else {
            delete head->val;
//            head->next = nullptr;
//            head->prev = nullptr;
            delete head;
            head = next;
         }
      }
   }
}

// returns the quantity of nodes in the linked list
int Queue::getQuantity() {
	int count = 0;	// counts the # of nodes in the linked list
	QueueNode* node = head;

	// list is empty
	if (head == nullptr) {
		return 0;
	}

	// list is not empty
	else {
		// the list has at least 1 node
		count++;
		node = node->next;

		// loop until the list is empty
		while (node != head && node != nullptr) {
			if (node != head && node != nullptr) {
				count++;
			}
			node = node->next;
		}
	}
}