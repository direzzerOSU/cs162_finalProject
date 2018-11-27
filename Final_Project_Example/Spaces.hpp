/*****************************************************************************
** Program name: Space classes header
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the header for the various space classes.
The space class is the parent class for the StartRoom, TrollRoom, QuizRoom1,
QuizRoom2, and EndRoom subclasses. Each subclass has a unique action() and 
getItem() function. They all inherit functions for setting and getting top,
bottom, left, and right pointers as well as setting and getting the space name.
*****************************************************************************/

#ifndef SPACES_HPP
#define SPACES_HPP

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

// Parent Space class
class Space
{
protected:
	Space* top;
	Space* bottom;
	Space* right;
	Space* left;
	string name;
	int completed;
public:
	int virtual action() = 0;
	string virtual getItem() = 0;
	Space* menu(Space*);
	void setTop(Space*);
	void setBottom(Space*);
	void setRight(Space*);
	void setLeft(Space*);
	void setName(string);
	string getName();
	Space* getTop();
	Space* getBottom();
	Space* getLeft();
	Space* getRight();
};

// StartRoom subclass (inherits from Space)
class StartRoom : public Space
{
public:
	int action();
	string getItem();
};

// TrollRoom subclass (inherits from Space)
class TrollRoom : public Space
{
public:
	int action();
	string getItem();
};

// QuizRoom1 subclass (inherits from Space)
class QuizRoom1 : public Space
{
public:
	int action();
	string getItem();
};

// QuizRoom2 subclass (inherits from Space)
class QuizRoom2 : public Space
{
public:
	int action();
	string getItem();
};

// EndRoom subclass (inherits from Space)
class EndRoom : public Space
{
public:
	int action();
	string getItem();
};


#endif