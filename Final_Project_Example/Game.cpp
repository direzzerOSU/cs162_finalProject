/*****************************************************************************
** Program name: Game class implementation
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the class implementation for the Game class. The
Game class builds the playing area by linking together 6 rooms, keeps track of the
player's location, and facilitates any events that may occur.
*****************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stoi;

// runGame is the main engine of the CaveEscape program that handles the results of user actions and determines end conditions
void Game::runGame()
{
	// call setRooms to build the game board
	setRooms();

	// initialization
	Space* myRoom;
	Space* lastRoom;
	myRoom = room1;
	lastRoom = room1;
	int varDamage = 0;
	int moveDamage = 10;
	string itemReturn;
	int win = 0;
	string trash;

	// display starting status
	cout << "\nYOU AWAKEN IN THE CAVE...\n";
	displayStatus(myRoom);

	// display starting room menu and update current room when they move
	myRoom = myRoom->menu(myRoom);

	// player loses 10 (5 with dampening) energy per move
	player.takeDamage(moveDamage);

	// main loop until player escapes or runs out of energy
	while (player.getEnergy() > 0 && win != 1)
	{
		// call the current room's action function and store return
		varDamage = myRoom->action();

		// no damage taken = player defeated challenge
		if (varDamage == 0)
		{
			// call getItem to see if any new items or blessings need to be added
			itemReturn = myRoom->getItem();
			
			// give player dampening ability
			if (itemReturn == "Dampen")
			{
				player.setDampen();
			}
			// give player revive ability
			else if (itemReturn == "Revive")
			{
				player.setRevive();
			}
			// add Key to player's backpack
			else if (itemReturn == "Key")
			{
				myPack.addBack(itemReturn);
			}
		}
		// action return of -1 calls the rest function (up to 3 times)
		else if (varDamage == -1)
		{
			if (player.getRests() == 3)
			{
				cout << "No rests remain!\n";
			}
			else
			{
				player.rest();
			}
		}
		// action return of -2 tries to open the final door
		else if (varDamage == -2)
		{
			// chck if the player has 0, 1, or 2 keys (2 = player wins)
			if (!myPack.isEmpty())
			{
				if (myPack.itemSearch("Key") == 2)
				{
					cout << "\nThe lock opens, you escape!\nGame Over... Player wins!\n\n";
					win = 1;
				}
				else
				{
					cout << "The lock won't open yet... You are still missing 1 key.\n";
				}
			}
			else
			{
				cout << "The lock won't open yet... You still need to find 2 keys.\n";
			}
		}
		// return that is not -2, -1, or 0 = damage taken by player (challenge failed)
		else
		{
			player.takeDamage(varDamage);
			// return player to previous room
			myRoom = lastRoom;
		}
		// if exit conditions haven't been met, display status and let player make a new move
		if (player.getEnergy() > 0 && win != 1)
		{
			cout << "\nENTER to continue...";
			getline(cin, trash);
			displayStatus(myRoom);
			lastRoom = myRoom;
			myRoom = myRoom->menu(myRoom);
			player.takeDamage(moveDamage);
		}
	}

	// game exit
	cout << "Goodbye!\n";
}

// setRooms builds a random game board
void Game::setRooms()
{
	int trollCount = 0;
	int quizCount = 0;
	int quiz1Count = 0;
	int random;


	// randomize room layout (1 always start, 6 always end, troll room x2 + quiz room x2)
	room1 = new StartRoom();
	room1->setName("Room 1");

	// set room 2 (troll or quiz)
	random = rand() % 2;
	if (random == 0)
	{
		room2 = new TrollRoom();
		trollCount++;
	}
	else
	{
		random = rand() % 2;
		if (random == 0)
		{
			room2 = new QuizRoom1();
			quiz1Count++;
		}
		else
		{
			room2 = new QuizRoom2();
		}
		quizCount++;
	}
	room2->setName("Room 2");

	// set room 3 (troll or quiz)
	random = rand() % 2;
	if (random == 0)
	{
		room3 = new TrollRoom();
		trollCount++;
	}
	else
	{
		random = rand() % 2;
		if ((random == 0 && quiz1Count == 0) || (quiz1Count == 0 && quizCount == 1))
		{
			room3 = new QuizRoom1();
			quiz1Count++;
		}
		else
		{
			room3 = new QuizRoom2();
		}
		quizCount++;
	}
	room3->setName("Room 3");

	// set room 4 (troll or quiz)
	random = rand() % 2;
	if ((random == 0 && trollCount != 2) || quizCount == 2 )
	{
		room4 = new TrollRoom();
		trollCount++;
	}
	else
	{
		random = rand() % 2;
		if ((random == 0 && quiz1Count == 0) || (quiz1Count == 0 && quizCount == 1))
		{
			room4 = new QuizRoom1();
			quiz1Count++;
		}
		else
		{
			room4 = new QuizRoom2();
		}
		quizCount++;
	}
	room4->setName("Room 4");

	// set room 5 (troll or quiz)
	random = rand() % 2;
	if ((random == 0 && trollCount != 2) || quizCount == 2)
	{
		room5 = new TrollRoom();
		trollCount++;
	}
	else
	{
		random = rand() % 2;
		if ((random == 0 && quiz1Count == 0) || (quiz1Count == 0 && quizCount == 1))
		{
			room5 = new QuizRoom1();
			quiz1Count++;
		}
		else
		{
			room5 = new QuizRoom2();
		}
		quizCount++;
	}
	room5->setName("Room 5");

	// set room 6 (End Room)
	room6 = new EndRoom();
	room6->setName("Room 6");


	// Connect new rooms via pointers
	room1->setTop(room6);
	room1->setBottom(NULL);
	room1->setLeft(NULL);
	room1->setRight(room2);

	room2->setTop(room5);
	room2->setBottom(NULL);
	room2->setLeft(room1);
	room2->setRight(room3);

	room3->setTop(room4);
	room3->setBottom(NULL);
	room3->setLeft(room2);
	room3->setRight(NULL);

	room4->setTop(NULL);
	room4->setBottom(room3);
	room4->setLeft(room5);
	room4->setRight(NULL);

	room5->setTop(NULL);
	room5->setBottom(room2);
	room5->setLeft(room6);
	room5->setRight(room4);

	room6->setTop(NULL);
	room6->setBottom(room1);
	room6->setLeft(NULL);
	room6->setRight(room5);

}

// displayStatus shows the current state of the game / player
void Game::displayStatus(Space* roomIn)
{
	// print correct game board based on current room (passed in)
	cout << "\n\n******************************************************************************************\n\n";
	if (roomIn->getName() == "Room 1")
	{
		cout << "|---------------|---------------|---------------|\n";
		cout << "|       6       |               |               |\n";
		cout << "|     (EXIT)            5               4       |\n";
		cout << "|               |               |               |\n";
		cout << "|------| |------|------| |------|------| |------|\n";
		cout << "|               |               |               |\n";
		cout << "|    <('_')>            2               3       |\n";
		cout << "|               |               |               |\n";
		cout << "|---------------|---------------|---------------|\n";
	}
	else if (roomIn->getName() == "Room 2")
	{
		cout << "|---------------|---------------|---------------|\n";
		cout << "|       6       |               |               |\n";
		cout << "|     (EXIT)            5               4       |\n";
		cout << "|               |               |               |\n";
		cout << "|------| |------|------| |------|------| |------|\n";
		cout << "|               |               |               |\n";
		cout << "|       1            <('_')>            3       |\n";
		cout << "|    (START)    |               |               |\n";
		cout << "|---------------|---------------|---------------|\n";
	}
	else if (roomIn->getName() == "Room 3")
	{
		cout << "|---------------|---------------|---------------|\n";
		cout << "|       6       |               |               |\n";
		cout << "|     (EXIT)            5               4       |\n";
		cout << "|               |               |               |\n";
		cout << "|------| |------|------| |------|------| |------|\n";
		cout << "|               |               |               |\n";
		cout << "|       1               2            <('_')>    |\n";
		cout << "|    (START)    |               |               |\n";
		cout << "|---------------|---------------|---------------|\n";
	}
	else if (roomIn->getName() == "Room 4")
	{
		cout << "|---------------|---------------|---------------|\n";
		cout << "|       6       |               |               |\n";
		cout << "|     (EXIT)            5            <('_')>    |\n";
		cout << "|               |               |               |\n";
		cout << "|------| |------|------| |------|------| |------|\n";
		cout << "|               |               |               |\n";
		cout << "|       1               2               3       |\n";
		cout << "|    (START)    |               |               |\n";
		cout << "|---------------|---------------|---------------|\n";
	}
	else if (roomIn->getName() == "Room 5")
	{
		cout << "|---------------|---------------|---------------|\n";
		cout << "|       6       |               |               |\n";
		cout << "|     (EXIT)         <('_')>            4       |\n";
		cout << "|               |               |               |\n";
		cout << "|------| |------|------| |------|------| |------|\n";
		cout << "|               |               |               |\n";
		cout << "|       1               2               3       |\n";
		cout << "|    (START)    |               |               |\n";
		cout << "|---------------|---------------|---------------|\n";
	}
	else if (roomIn->getName() == "Room 6")
	{
		cout << "|---------------|---------------|---------------|\n";
		cout << "|               |               |               |\n";
		cout << "|    <('_')>            5               4       |\n";
		cout << "|               |               |               |\n";
		cout << "|------| |------|------| |------|------| |------|\n";
		cout << "|               |               |               |\n";
		cout << "|       1               2               3       |\n";
		cout << "|    (START)    |               |               |\n";
		cout << "|---------------|---------------|---------------|\n";
	}

	// print energy, rests, and backpack contents
	cout << "\nPlayer Energy: " << player.getEnergy();
	cout << "\nPlayer Rests Used: " << player.getRests();
	cout << "\nBackpack Contents: ";
	if (myPack.isEmpty())
	{
		cout << "EMPTY\n";
	}
	else
	{
		myPack.printQueue();
	}
}

// Destructor to delete dynamically allocated memory
Game::~Game()
{
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	delete room6;
}