/************************************************************************************
*Filename: Goblin.hpp
*Name: John R Toth
*Date: 5/4/15
*Description: Goblin header file
************************************************************************************/

#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Character.hpp"
#include "Arena.hpp"

#include <iostream>
using namespace std; 


class Goblin: public Character
{
protected: 
	//member variables 
	int newStrength;
	bool status;


public: 
	//default constructor
	Goblin(); 

	//mutator fn that sets characters status
	void setStatus(bool);
		//setStatus - sets the status of the Goblin
		//@param bool - status of Goblin

	//Accessor fn that gets characters status
	bool getStatus();
		
	//accessor fn getStrength
	int getStrength();
	
	//mutator fn setStregth
	void setStrength(int);
		//setStrength - sets the strength of the Goblin
		//@param int - strength of Goblin 


	void attack();
	void defense();
	void armor(int);
	void strength();

};
#endif