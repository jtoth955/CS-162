/***********************************************************************************
*Filename: LoadedDice.hpp
*Name: John R Toth
*Date: 4/17/15
*Description: Header file for LoadedDice Class, doubles result of die roll
*Input: None
*Output: None
***********************************************************************************/

#include <iostream> 
using namespace std; 

#ifndef LoadedDice_HPP
#define LoadedDice_HPP

//class LoadDice inherits from class Dice
class LoadedDice : public Dice 
{

public: 

	LoadedDice();

	//accessor fns from class dice
	void setNumFaces(int);

	//override Roll fn from class Dice
	int Roll() const;

private: 
	//access to class Dice member variables
	int numDice; 
	int newNumFaces;

};
#endif