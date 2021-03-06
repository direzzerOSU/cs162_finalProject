/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

// begin the include guard
#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

// include the files that are required for the input validation function to run properly
#include "character.hpp"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
#include<limits>

class Character;

// works cited
   // (1) http://www.cplusplus.com/reference/istream/istream/ignore/

// function prototype

// validate the user's input is the correct type (i.e., int and char, respectively)
void intValidation(int&);
void charValidation(char&);
void floatValidation(float& value);

// check for a valid yes or no selection from user input
void validYesNo(int&);

// validate the user's input is a correct menu option
void validMonsterSelection(Character*, int&);

#endif   // end of include guard
