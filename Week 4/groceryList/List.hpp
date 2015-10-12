/************************************************************************************
*Filename: List.hpp
*Name: John R Toth
*Date: 4/26/15
*Description: List header file
************************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "ClubItems.hpp"
#include "Items.hpp"

#include <iostream> 
#include <vector> 
using namespace std; 

class List
{
private: 
	vector<Items> product;
	vector<ClubItems> discount;

public: 
	List();
	void addProduct(); 
	void displayList();
	void remove();
	void displayTotal();
	 
};
#endif