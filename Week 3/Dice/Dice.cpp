/***********************************************************************************
*Filename: Dice.hpp
*Name: John R Toth
*Date: 4/17/15
*Description: Header file for Dice Class, simulates dice roll and sets number of 
*faces on the die
*Input: Recieves user input for number of faces on die. Also produces die roll value 
*based on die faces
*Output: returns die roll total back to main  
***********************************************************************************/

#include <ctime> 
#include <iostream> 
#include <cstdlib>
#include "Dice.hpp"
using namespace std; 

//default constructor
Dice::Dice() {
	newNumFaces = 6;
	numDice = 2;
}

//destructor fn 
Dice::~Dice() {

}
//number of die loop
int Dice::Roll() const {
	int total = 0;
	for (int i = 0; i < numDice; i++)
	{
		total = total+rand()%newNumFaces+1;
	}
	return total; 
}
//member variable newNumFace gets changed to input param, faces
void Dice::setNumFaces(int faces) {
	if(faces > 0)
		newNumFaces = faces;
	
	else{
		Dice::newNumFaces=0;
		cout << "Error, bad number of faces\n";
		}
}
