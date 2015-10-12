/************************************************************************************
*Filename: Barbarian.hpp
*Name: John R Toth
*Date: 5/4/15
*Description: Barbarian header file
************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
#include "Arena.hpp"

#include <iostream>
using namespace std; 


class Barbarian: public Character
{
protected: 
	//member variables 
	int newStrength;
	bool status;


public: 
	//default constructor
	Barbarian(); 

	//mutator fn that sets characters status
	void setStatus(bool);
		//setStatus - sets the status of the Barbarian
		//@param bool - status of Barbarian

	//Accessor fn that gets characters status
	bool getStatus();
		
	//accessor fn getStrength
	int getStrength();
	
	//mutator fn setStregth
	void setStrength(int);
		//setStrength - sets the strength of the Barbarian
		//@param int - strength of Barbarian 


	void attack();
	void defense();
	void armor(int);
	void strength();

};
#endif