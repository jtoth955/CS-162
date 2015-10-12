/************************************************************************************
*Filename: ClubItems.cpp
*Name: John R Toth
*Date: 4/26/15
*Description: ClubItems implentation file
*Input: None
*Output: None
************************************************************************************/


#include "ClubItems.hpp"
#include "Items.hpp"
#include "List.hpp"


#include <iostream> 

using namespace std; 	

ClubItems::ClubItems()
: Items()
{
	setPrice(this->price)
}

ClubItems::ClubItems(string name, double size, int quantity, double price, char sale)	//base constructor
: Items(name, size, quantity, price, sale) //calling the base constructor
{
	setPrice(price); 
}

void ClubItems::setPrice(double price) 
{this->price = price * .9;}

