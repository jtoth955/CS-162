/***********************************************************************************
*Filename: LoadedDice.cpp
*Name: John R Toth
*Date: 4/17/15
*Description: File for LoadedDice Class, simulates dice roll and doubles outcome up 
*to max value of die faces
*Input: Recieves user input for number of faces on die. Also overrides Die Roll fn 
*to alter output to roll total *2, or equate to total max value of die faces
*Output: returns amended die roll total back to main  
***********************************************************************************/

#include <ctime> 
#include <iostream> 
#include <cstdlib>
#include "Dice.hpp"
#include "LoadedDice.hpp"
using namespace std;

LoadedDice::LoadedDice() {
	newNumFaces = 6;
	numDice = 2;
}

//member variable newNumFace gets changed to input param, faces
void LoadedDice::setNumFaces(int faces){
	newNumFaces = faces;
}
//number of die loop, overrided by class LoadedDice	
int LoadedDice::Roll() const {
	cout << "test" ;
	cout << numDice <<endl; 


	int total = 0;
	for (int i = 0; i < numDice; i++)
	{
		total = (total+rand()%newNumFaces+1) * 2;	
		
		if(total > newNumFaces)
		{	
			return newNumFaces * 2;
		}
		if(total <= newNumFaces)
			return total;
	}
	return total; 
}
