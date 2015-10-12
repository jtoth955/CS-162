/************************************************************************************
*Filename: Blue.hpp
*Name: John R Toth
*Date: 5/4/15
*Description: Blue Men header file
************************************************************************************/

#ifndef BLUE_HPP
#define BLUE_HPP

#include "Character.hpp"
#include "Arena.hpp"

#include <iostream>
using namespace std; 


class Blue: public Character
{
protected: 
	//member variables 
	int newStrength;
	bool status;


public: 
	//default constructor
	Blue(); 

	//mutator fn that sets characters status
	void setStatus(bool);
		//setStatus - sets the status of the Blue Men
		//@param bool - status of Blue Men

	//Accessor fn that gets characters status
	bool getStatus();
		
	//accessor fn getStrength
	int getStrength();
	
	//mutator fn setStregth
	void setStrength(int);
		//setStrength - sets the strength of the Blue Men
		//@param int - strength of Blue Men


	void attack();
	void defense();
	void armor(int);
	void strength();

};
#endif