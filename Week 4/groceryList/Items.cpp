/************************************************************************************
*Filename: Items.cpp
*Name: John R Toth
*Date: 4/26/15
*Description: Items implementation file, holds regular price objects
*Input: None
*Output: None
************************************************************************************/

#include "List.hpp"
#include "Items.hpp"

#include <iostream> 
#include <string> 

using namespace std; 

//default constructor
Items::Items() {
	
}
//overload constructor
Items::Items(string n, double s, int q, double p, char m) {
	name = n;
	size = s;
	quantity = q;
	price = p;
	sale = m;
}

string Items::getName() {
	return name; 
}
double Items::getSize() {
	return size;
}
double Items::getPrice() {
	return price;
}
int Items::getQuantity() {
	return quantity;
}
char Items::getSale() {
	return sale;
}
