/***********************************************************************************
*Filename: Main.cpp
*Name: John R Toth
*Date: 4/17/15
*Description: Main Fn that prompts user for number of faces per die, roll the dice 
*and sum the results  
*Input: User supplies number of die faces
*Output: Displays sum of die rolls 
***********************************************************************************/

#include <iostream>
#include <fstream> 
#include <ctime> 
#include <cstdlib> 
#include "Dice.hpp"
#include "LoadedDice.hpp"


int main() 
{
	int faces;
	int roll;
	unsigned seed;
	seed = (time(0));
	srand(seed);
	

	cout << "How many faces does the die have? ";
	cin  >> faces;

	cout << "How many times would you like to roll the die? ";
	cin  >> roll;

	//create ofstream object and external file 
	ofstream outPutFile("DiceComparo.txt");

/***********************************************************************************
*Description: dice fn call, sends user specified # of faces to roll fn in Dice class 
*Parameters: setNumFaces and roll
***********************************************************************************/


	cout << "Regular Dice output: " << endl;
	outPutFile << "Regular Dice output: " << endl;
	
	//call member fns to set the number of faces 
	Dice Object;
		Object.setNumFaces(faces);

	//simulate Dice roll with Dice class
	for(int y = 0; y < roll; y++)
	{
		outPutFile << Object.Roll() << ", " <<endl;
		cout << Object.Roll() << endl;	
		
	}	
	

/***********************************************************************************
*Description: loaded dice fn call, sends user specified # of faces to override fn 
*in LoadedDice class
*Parameters: setNumFaces and roll
***********************************************************************************/

	cout << "Loaded Dice output: " << endl;
	outPutFile << "Loaded Dice output: " << endl;
	LoadedDice Object2;
		Object2.setNumFaces(faces);
	
	//simulate Dice roll with LoadedDice class
	for(int x = 0; x < roll; x++)
	{
		outPutFile << Object2.Roll() << ", " << endl;
		cout << Object2.Roll() << endl; 

	}

	
	//close the external file
	outPutFile.close();
	cout << "Data written to DiceComparo.txt\n";

return 0;
}