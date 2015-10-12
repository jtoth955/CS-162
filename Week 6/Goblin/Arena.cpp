/***********************************************************************************
*Filename: Arena.cpp
*Name: John R Toth
*Date: 5/4/15
*Description:
*Input: 
*Output:   
***********************************************************************************/

#include "Arena.hpp"

#include <iostream> 
#include <ctime>
#include <cstdlib>

using namespace std; 

//default constructor 
Arena::Arena() {
	newNumFaces = 6;
	newNumDice = 2;
	defend = 0;
	attack = 0;
	goblinFact = false;
}

//number of die loop
int Arena::Roll() const {

	int total = 0;
		
		for (int i = 0; i < newNumDice; i++)
		{
			total = total+rand()%newNumFaces+1;
		}
 	
	return total;
}

//member variable newNumFace gets changed to input param, faces
void Arena::setNumFaces(int faces) {
		newNumFaces = faces;
}

//member variable newNumDice gets changed to input param, dice
void Arena::setNumDice(int dice) {
		newNumDice = dice;
}
void Arena::setAttackRoll(int a) {
		attack = a;
}
void Arena::setDefendRoll(int d) {
		defend = d;
}
void Arena::setGoblinFactor(bool g) {
		goblinFact = g;
}
bool Arena::getGoblinFactor() {
		return goblinFact; 
}
int Arena::deathBlow(){
	
	int damage;

	

	if(getGoblinFactor() == false)
	{
		cout <<"The Defender fought with a value of: "<< defend << endl;

			if(attack > defend)
			{
				damage = attack - defend;
			}
			
				if(attack == defend) 
				{
					cout << "The attack value equaled the defense value! " << endl;
					damage = 0;
				}
				
					if(defend > attack)
					{
						cout << "The defender overpowered the attacker on that strike! " << endl;
						damage = 0;
					}	
	}
	else if(getGoblinFactor() == true)
	{
		cout << "The defender's achilles has been cut! " << endl;

		cout <<"The Defender fought with a value of: "<< defend << endl;

		defend *= .5;
		cout << "New defend value: " << defend << endl;

			if(attack > defend)
			{
				damage = attack - defend;
			}
			
				if(attack == defend) 
				{
					cout << "The attack value equaled the defense value! " << endl;
					damage = 0;
				}
				
					if(defend > attack)
					{
						cout << "The defender overpowered the attacker on that strike! " << endl;
						damage = 0;
					}		
	}			

	return damage; 

	
}














