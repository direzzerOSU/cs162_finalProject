/*/*****************************************************************************
** Program name: Player class implementation
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the implementation for the player class. The player
		class store player specific stats (energy, rests, dampen, revive), and functions
		for updating those stats, resting (restore energy), or taking damage.
*****************************************************************************/

#include "Player.hpp"
#include <iostream>
using std::cout;
using std::endl;

// Constructor that sets starting stats
Player::Player()
{
	energy = 100;
	rests = 0;
	dampen = 0;
	revive = 0;
}

// takeDamage updates the player's energy based on damage taken, also takes dampening into account
void Player::takeDamage(int dmgIn)
{
	// cut damage in half if dampening is active
	if (dampen == 1)
	{
		dmgIn = dmgIn / 2;
	}
	// update energy total
	energy = energy - dmgIn;

	// if energy reaches 0, either revive or print game over
	if (energy <= 0)
	{
		if (revive == 1)
		{
			energy = 100;
			revive = 0;
			cout << "\nYour energy reaches 0, but the gnome's REVIVE blessing activates and returns you to full energy\n";
		}
		else
		{
			cout << "\nAll of your energy is gone, game over!\n\n";
		}
	}
}

// return player energy
int Player::getEnergy()
{
	return energy;
}

// return player rests
int Player::getRests()
{
	return rests;
}

// return dampen state
int Player::getDampen()
{
	return dampen;
}

// return revive state
int Player::getRevive()
{
	return revive;
}

// activate rest, restore energy to 100
void Player::rest()
{
	energy = 100;
	rests++;
}

// add dampening to player
void Player::setDampen()
{
	dampen = 1;
}

// add revive to player
void Player::setRevive()
{
	revive = 1;
}