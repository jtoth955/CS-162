/***********************************************************************************
*Filename: Dice.hpp
*Name: John R Toth
*Date: 4/17/15
*Description: Header file for Dice Class, simulates dice roll and sets number of 
*faces on the die
*Input: None
*Output: None
***********************************************************************************/

#include <iostream> 
#include <ctime> 

using namespace std; 

#ifndef Dice_HPP
#define Dice_HPP

class Dice {

public:

	//default constructor 
	Dice(); 

	//destructor fn
	~Dice();

	//fn to simulate dice roll
	int Roll() const; 

	//mutator fns
	void setNumFaces(int);
		//seetNumFaces - sets number of sides to die
		//@param int - number of sides

	void setRoll(int);
		//setRoll - sets number of die rolls
		//@param int - number of rolls

private: 

	//member variables
	int newNumFaces; 
	int numDice;

};
#endif