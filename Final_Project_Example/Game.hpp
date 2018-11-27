/*****************************************************************************
** Program name: Game class header
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the class header for the Game class. The
Game class builds the playing area by linking together 6 rooms, keeps track of the
player's location, and facilitates any events that may occur.
*****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Spaces.hpp"
#include "Player.hpp"
#include "Backpack.hpp"
#include <string>
using std::string;
using std::endl;
using std::cout;

class Game
{
private:
	Player player;
	Backpack myPack;
	Space* room1;
	Space* room2;
	Space* room3;
	Space* room4;
	Space* room5;
	Space* room6;
public:
	void runGame();
	void setRooms();
	void displayStatus(Space*);
	~Game();
};

#endif
