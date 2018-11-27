/*****************************************************************************
** Program name: Player class header
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the header for the player class. The player
		class store player specific stats (energy, rests, dampen, revive), and functions
		for updating those stats, resting (restore energy), or taking damage.
*****************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using std::string;

// Parent Character class
class Player
{
private:
	int energy;
	int rests;
	int dampen;
	int revive;

public:
	Player();
	int getEnergy();
	int getRests();
	int getDampen();
	int getRevive();
	void setDampen();
	void setRevive();
	void takeDamage(int);
	void rest();
};

#endif