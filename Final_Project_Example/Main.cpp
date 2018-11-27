/*****************************************************************************
** Program name: CaveEscape
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - A text based game in which the player moves through
		various rooms in a cave completing challenges and collecting items in an
		effort to ultimately escape.
*****************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include<ctime>
using std::time;
#include<cstdlib>
using std::srand;
using std::string;
using std::cout;
using std::cin;
using std::endl;

// start main
int main()
{
	Game myGame;

	// seed random
	srand(time(0));

	// Display the game instructions and basic map
	cout << "\n******************************************************************************************\n";
	cout << "Welcome to Cave Escape!\n\n";
	cout << "You must find your way out of the Cave by moving through the various rooms\n";
	cout << "and overcoming any obstacles you encounter along the way. If you find yourself\n";
	cout << "low on energy, you may navigate back to the starting area to rest. Use this wisely\n";
	cout << "though, as you may only do it 3 times! Your energy will start at 100 and decrease\n";
	cout << "by 10 every time you change rooms in the cave. You may encounter other challenges\n";
	cout << "along the way that could drain your energy also, so be careful!\n";

	cout << "\nThe basic game play area is as follows...\n\n";
	cout << "|---------------|---------------|---------------|\n";
	cout << "|       6       |               |               |\n";
	cout << "|     (EXIT)            5               4       |\n";
	cout << "|               |               |               |\n";
	cout << "|------| |------|------| |------|------| |------|\n";
	cout << "|               |               |               |\n";
	cout << "|       1               2               3       |\n";
	cout << "|    (START)    |               |               |\n";
	cout << "|---------------|---------------|---------------|\n";
	cout << "\n******************************************************************************************\n";

	// call runGame() to let the player start the game
	myGame.runGame();

	return 0;
}