/*****************************************************************************
** Program name: Space classes implementation
** Author: Dan Koning
** Date: 11/28/2017
** Description: Final Project - This is the implementation for the various space classes.
The space class is the parent class for the StartRoom, TrollRoom, QuizRoom1,
QuizRoom2, and EndRoom subclasses. Each subclass has a unique action() and
getItem() function. They all inherit functions for setting and getting top,
bottom, left, and right pointers as well as setting and getting the space name.
*****************************************************************************/

#include "Spaces.hpp"

// menu builds a unique menu based on the current room's pointer, then returns the user's choice
Space* Space::menu(Space* myRoom)
{
	// initialization
	int menuCount = 0;
	Space* tempRoom;
	string input;
	int userChoice;
	int badIn = 1;

	// build menu options for each direction without a NULL pointer
	tempRoom = myRoom->getLeft();
	if (tempRoom != NULL)
	{
		menuCount++;
		cout << "\n[" << menuCount << "] - Open the left door to " << tempRoom->getName();
	}
	tempRoom = myRoom->getRight();
	if (tempRoom != NULL)
	{
		menuCount++;
		cout << "\n[" << menuCount << "] - Open the right door to " << tempRoom->getName();
	}
	tempRoom = myRoom->getTop();
	if (tempRoom != NULL)
	{
		menuCount++;
		cout << "\n[" << menuCount << "] - Climb up the ladder to " << tempRoom->getName();
	}
	tempRoom = myRoom->getBottom();
	if (tempRoom != NULL)
	{
		menuCount++;
		cout << "\n[" << menuCount << "] - Climb down the ladder to " << tempRoom->getName();
	}

	// get user selection + validate
	while (badIn == 1)
	{
		cout << "\nChoose an action: ";
		getline(cin, input);

		badIn = 0;
		// length check
		if (input.length() != 1)
		{
			badIn = 1;
		}

		// character by character type check
		if (badIn == 0)
		{
			for (int i = 0; i < input.length(); i++)
			{
				if (!isdigit(input[i]))
				{
					badIn = 1;
				}
			}
		}

		// range check
		if (badIn == 0)
		{
			userChoice = stoi(input);
			if (userChoice < 1 || userChoice > menuCount)
			{
				badIn = 1;
			}
		}

		// Alert user to bad input
		if (badIn == 1)
		{
			cout << "Invalid choice, try again...\n";
		}
	}


	// determines the player's new room based on their selection
	int count = 0;
	tempRoom = myRoom->getLeft();
	if (tempRoom != NULL) 
	{
		count++;
	}
	if (count != userChoice)
	{
		tempRoom = myRoom->getRight();
		if (tempRoom != NULL)
		{
			count++;
		}
	}
	if (count != userChoice)
	{
		tempRoom = myRoom->getTop();
		if (tempRoom != NULL)
		{
			count++;
		}
	}
	if (count != userChoice)
	{
		tempRoom = myRoom->getBottom();
		if (tempRoom != NULL)
		{
			count++;
		}
	}

	// return the player's move choice
	return tempRoom;
}

// set top
void Space::setTop(Space* topIn)
{
	top = topIn;
}

// set bottom
void Space::setBottom(Space* botIn)
{
	bottom = botIn;
}

// set left
void Space::setLeft(Space* leftIn)
{
	left = leftIn;
}

// set right
void Space::setRight(Space* rightIn)
{
	right = rightIn;
}

// set name
void Space::setName(string nameIn)
{
	name = nameIn;
}

// return name
string Space::getName()
{
	return name;
}

// return top
Space* Space::getTop()
{
	return top;
}

// return bottom
Space* Space::getBottom()
{
	return bottom;
}

// return left
Space* Space::getLeft()
{
	return left;
}

// return right
Space* Space::getRight()
{
	return right;
}

// startRoom's action function
int StartRoom::action()
{
	int returnVal;
	string input;
	int badIn = 1;

	// give player the option to rest or continue ( return -2 to rest or 0 to continue)
	while (badIn == 1)
	{
		cout << "\nEnter 1 to rest (restore energy) or 2 to continue: ";
		getline(cin, input);
		if (input == "1")
		{
			badIn = 0;
			returnVal = -1;
		}
		else if (input == "2")
		{
			badIn = 0;
			returnVal = 0;
		}
		else
		{
			cout << "Invalid entry, try again..." << endl;
		}
	}
	return returnVal;
}

// startRoom's getItem function, returns "0", no item
string StartRoom::getItem()
{
	return "0";
}

// TrollRoom's action function
int TrollRoom::action()
{
	int retDmg = 0;
	int passFight = 0;
	int trollRoll = 0;
	int playerRoll = 0;
	
	// if this room has not already been completed...
	if (completed == 0)
	{
		// fight a Cave Troll and display results
		cout << "\nA Cave Troll jumps out of the shadows and attacks you!\n";
		playerRoll = rand() % 20 + 1;
		trollRoll = rand() % 20 + 1;
		cout << "Player Roll: " << playerRoll << " / Troll Roll: " << trollRoll << endl;
		
		// player wins
		if (playerRoll >= trollRoll)
		{
			passFight = 1;
		}

		// troll wins, dmg = 40
		if (passFight == 0)
		{
			retDmg = 40;
			cout << "The cave troll punts you, lose 40 energy (20 if dampened)\nYou are sent back to the previous room!\n";
		}
		// no damage for player win, print reward
		else
		{
			retDmg = 0;
			cout << "You slay the cave troll! His body magically disappears and leaves behind something shiny\n\nItem Added: KEY\n";
		}
	}
	// room already completed
	else
	{
		cout << "\nThe room is empty, you have already been here...\n";
	}

	// return damage
	return retDmg;
}

// TrollRoom's getItem function
string TrollRoom::getItem()
{
	// return "Key" if this is the first time completing the room, mark complete
	if (completed == 0)
	{
		completed = 1;
		return "Key";
	}
	else
	{
		return "0";
	}
}

// QuizRoom's action function
int QuizRoom1::action()
{
	int retDmg = 0;
	int passQuiz = 0;
	int flipResult;

	// if the room hasn't been completed...
	if (completed == 0)
	{
		cout << "\nA gnome materializes in front of you, before you have a chance to say anything he yells \"HEADS OR TAILS?\"...\n";

		int badIn = 1;
		string input;
		int guess;

		// get user's heads or tails guess + validate
		while (badIn == 1)
		{
			cout << "Enter 1 for \"HEADS\" or 2 for \"TAILS\": ";
			getline(cin, input);
			if (input == "1" || input == "2")
			{
				guess = stoi(input);
				badIn = 0;
			}
			else
			{
				cout << "Invalid entry, try again..." << endl;
			}
		}
		
		// get flip result
		flipResult = rand() % 2 + 1;
		if (flipResult == 1)
		{
			cout << "The gnome flips his coin in the air and, when it lands, you see that it shows HEADS!\n";
		}
		else
		{
			cout << "The gnome flips his coin in the air and, when it lands, you see that it shows TAILS!\n";

		}
		// if player guessed correctly, pass
		if (guess == flipResult)
		{
			passQuiz = 1;
		}

		// 20 damage for failing
		if (passQuiz == 0)
		{
			retDmg = 20;
			cout << "The gnome whacks you with his stick for guessing wrong, lose 20 energy (10 if dampened)\nYou are sent back to the previous room!\n";
		}
		// return 0 if pass and print reward (REVIVE)
		else
		{
			retDmg = 0;
			cout << "The gnome tells you good job and blesses your journey ahead...\n\nBlessing Added: REVIVE (The first time you die, you will magically return to full energy)\n";
		}
	}
	// player has already completed this room
	else
	{
		cout << "\nThe room is empty, you have already been here...\n";
	}

	// return damage
	return retDmg;
}

// QuizRoom1's getItem function
string QuizRoom1::getItem()
{
	// return "Revive" blessing if this is the first time, set complete to 1
	if (completed == 0)
	{
		completed = 1;
		return "Revive";
	}
	else
	{
		return "0";
	}
}

// QuizRoom2's action function
int QuizRoom2::action()
{
	int retDmg = 0;
	int passQuiz = 0;
	// if not already completed...
	if (completed == 0)
	{
		cout << "\nA gnome materializes in front of you, he looks at you for a minute, then asks... \"What came first... the chicken... or the egg...\"\n";
		int badIn = 1;
		string input;
		int guess;

		// get user answer
		while (badIn == 1)
		{
			cout << "Enter 1 for \"CHICKEN\", 2 for \"EGG\", or 3 to whine about how this is a trick and there is no right answer: ";
			getline(cin, input);
			if (input == "1" || input == "2" || input == "3")
			{
				guess = stoi(input);
				badIn = 0;
			}
			else
			{
				cout << "Invalid entry, try again..." << endl;
			}
		}

		// 3 is the right answer, pass
		if (guess == 3)
		{
			passQuiz = 1;
		}

		// return 20 dmg if user didn't pick 3
		if (passQuiz == 0)
		{
			retDmg = 20;
			if (guess == 1)
			{
				cout << "The gnome laughs in your face... \"HOW CAN THERE BE A CHICKEN THAT DIDN'T START AS AN EGG!?!?\"\nHe whacks you with his stick...Lose 20 energy (10 if dampened)\nYou are sent back to the previous room!\n";
			}
			else
			{
				cout << "The gnome laughs in your face... \"HOW CAN THERE BE AN EGG WITHOUT A CHICKEN TO LAY IT!?!?\"\nHe whacks you with his stick...Lose 20 energy (10 if dampened)\nYou are sent back to the previous room!\n";

			}
		}

		// user picked 3
		else
		{
			retDmg = 0;
			cout << "The gnome applauds your wise answer and blesses your journey ahead...\n\nBlessing Added: DAMPEN (All damage taken reduced by 50%)\n";
		}
	}
	// already completed
	else
	{
		cout << "\nThe room is empty, you have already been here...\n";
	}

	// return dmg
	return retDmg;
}

// QuizRoom2's getItem function
string QuizRoom2::getItem()
{
	// reward "Dampen" if not already completed
	if (completed == 0)
	{
		completed = 1;
		return "Dampen";
	}
	else
	{
		return "0";
	}
}

// EndRoom's action function
int EndRoom::action()
{
	int returnVal;
	string input;
	int badIn = 1;

	// Ask user if they want to try to open the final door or not + validate (return -2 to try, 0 to skip)
	while (badIn == 1)
	{
		cout << "\nEnter 1 to try to open the locked door or 2 to continue: ";
		getline(cin, input);
		if (input == "1")
		{
			badIn = 0;
			returnVal = -2;
		}
		else if (input == "2")
		{
			badIn = 0;
			returnVal = 0;
		}
		else
		{
			cout << "Invalid entry, try again..." << endl;
		}
	}
	return returnVal;
}

// EndRoom's getItem function (return "0", no item)
string EndRoom::getItem()
{
	return "0";
}