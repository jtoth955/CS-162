/************************************************************************************
*Filename: ClubItems.hpp
*Name: John R Toth
*Date: 4/26/15
*Description: ClubItems header file
************************************************************************************/

#ifndef CLUBITEMS_HPP
#define CLUBITEMS_HPP


#include "Items.hpp"
using namespace std; 

//class ClubItems inherits from class Items
class ClubItems : public Items
{

public:
	ClubItems(); //default constructor, calling Items
	

	ClubItems(string name, double size, int quantity, double price, char sale);	//base constructor
	

	void setPrice(double price);
	

};
#endif 