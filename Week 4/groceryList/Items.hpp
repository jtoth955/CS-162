/************************************************************************************
*Filename: Items.hpp
*Name: John R Toth
*Date: 4/26/15
*Description: Items header file
************************************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <vector> 
#include <string> 

using namespace std;

class Items
{
protected: 
	string name;
	int quantity;
	double size; 
	double price;
	char sale;

public:
	Items();
	Items(string name, double size, int quantity, double price, char sale);
	string getName(); 
	double getSize(); 
	int getQuantity(); 
	double getPrice(); 
	char getSale(); 
	

};
#endif