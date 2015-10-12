/************************************************************************************
*Filename: Arena.hpp
*Name: John R Toth
*Date: 5/4/15
*Description: Arena header file
************************************************************************************/

#ifndef ARENA_HPP
#define ARENA_HPP

//#include "Character.hpp"

#include <iostream>
using namespace std; 


class Arena {

private: 
	//member variables
	int newNumFaces;
	int newNumDice; 
	int attack;
	int defend;
	bool goblinFact;


public: 

	//default constructor
	Arena(); 

	//fn to simulate die roll
	int Roll() const; 

	//mutator fn
	void setNumFaces(int); 
		//setNumFaces - sets number of sides of die
		//@param int - number of sides 

	void setNumDice(int);
		//setNumDiece - sets number of die used
		//@param int - number of die

	void setRoll(int); 
		//setRoll - sets number of die rolls
		//@param int - number of rolls

	void setAttackRoll(int);
		//attackRoll - accepts the roll from the attacker
		//@param int - the value of the die roll

	void setDefendRoll(int);
		//defendRoll - accepts the roll from the defender
		//@param int - the value of the die roll

	void setGoblinFactor(bool);

	bool getGoblinFactor();

	int deathBlow();

};
#endif

