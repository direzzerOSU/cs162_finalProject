///*********************************************************************
//** Program name: Circular Linked List
//** Author: Ryan DiRezze
//** Date: November 11, 2018
//** Description: Defines classes and structs to implement the Circular
//   Linked List program.
//*********************************************************************/
//
//#ifndef BACKPACK_H
//#define BACKPACK_H
//
//#include "circularLinkedList.hpp"
//
//class itemQueue;
//struct itemNode;
//
//// (base class) define items that the player can use (& are stored within the backpack)
//struct Item {
//	// attributes
//	int health = 0;
//	int attack = 0;
//	int defens = 0;
//	int armor = 0;
//	int speed = 0;
//
//	// neutral
//	int weapons = 0;
//};
//
////#######################################################
//// specific items
//
//// full health potion (restores full health)
//struct fullHealthPotion : Item {
//	health = 100;
//};
//
//// minor health potion
//struct minorHealthPotion : Item {
//	health = 20;
//};
//
//// attack increase potion
//struct attackPotion {
//	attack = 20;
//};
//
//// defense increase potion
//struct defensePotion {
//	defense = 20;
//};
//
//// attack (decrease) poison
//struct attackPoision {
//	attack = -20;
//};
//
//// defense (decrease) poison
//struct defensePoison {
//	defense = -20;
//};
//
////######################################################
//// backpack (of items)
//
//// define backpack (as a class)
//class Backpack {
//public:
//	Backpack();
//	~Backpack();
//	//void view();
//private:
//	itemQueue* items = nullptr;
//};
//#endif