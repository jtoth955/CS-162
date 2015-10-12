/************************************************************************************
*Filename: Reptile.hpp
*Name: John R Toth
*Date: 5/4/15
*Description: Reptile header file
************************************************************************************/

#ifndef REPTILE_HPP
#define REPTILE_HPP

#include "Character.hpp"
#include "Arena.hpp"

#include <iostream>
using namespace std; 


class Reptile: public Character
{
protected: 
	//member variables 
	int newStrength;
	bool status;


public: 
	//default constructor
	Reptile(); 

	//mutator fn that sets characters status
	void setStatus(bool);
		//setStatus - sets the status of the Reptile People
		//@param bool - status of Reptile People

	//Accessor fn that gets characters status
	bool getStatus();
		
	//accessor fn getStrength
	int getStrength();
	
	//mutator fn setStregth
	void setStrength(int);
		//setStrength - sets the strength of the Reptile People
		//@param int - strength of Reptile People 


	void attack();
	void defense();
	void armor(int);
	void strength();

};
#endif

