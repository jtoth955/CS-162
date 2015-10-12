/***********************************************************************************
*Filename: Blue.cpp
*Name: John R Toth
*Date: 5/4/15
*Description: Blue Men class inherits from Character class through Polymorphism
*Input: None
*Output: Amount of damage given and received to other characters, as well as current
*status of character 
***********************************************************************************/


#include "Blue.hpp"
#include "Arena.hpp"
#include "Character.hpp"

#include <iostream> 
#include <ctime>
using namespace std; 

//object declarations
Blue blu;
Arena battle1;

const int BL_ARMOR = 3;
const int BL_ATTACK_DIE = 2;
const int BL_ATTACK_FACE = 10;
const int BL_DEFEND_DIE = 3;
const int BL_DEFEND_FACE = 6;

//default constructor
Blue::Blue() {
	newStrength = 12;
	status = true;
}

void Blue::setStatus(bool s) {
	status = s;
}

bool Blue::getStatus() {
	return status;
}
/*********************************************************************************
*Description - Attack fn Fn that passes number of die and die faces to Arena fn 
*Parameters - CONST for number of die and die faces
*********************************************************************************/
void Blue::attack() {
	
	int attack;

	battle1.setNumFaces(BL_ATTACK_FACE);
	battle1.setNumDice(BL_ATTACK_DIE);
	attack = battle1.Roll();

	cout << "The Blue Men delivered a heavy blow to the opponent with a force of: " << attack << endl;
	
	battle1.setAttackRoll(attack);

}
/*********************************************************************************
*Description - Defense fn 
*fn that send number of die and faces to Arena class and assesses the amount of 
*damage received 
*Parameters - Passes the amount of damage received to the the Armor fn, using 
polymorphism
*********************************************************************************/
void Blue::defense() {

	int defend, damage, impact;

	battle1.setNumFaces(BL_DEFEND_FACE);
	battle1.setNumDice(BL_DEFEND_DIE);
	defend = battle1.Roll();	

	battle1.setDefendRoll(defend);
	damage = battle1.deathBlow();

		if(damage == 0)
		{
			cout << "No damage!!" << endl;
		}
			
			else if(damage > BL_ARMOR)
			{	
				impact = damage - BL_ARMOR;
				cout << "The Blue Men were injured! Because of armor, it only had an impact of: -"<< impact << endl;
			}
			
				else if((damage > 0) && (damage <= BL_ARMOR))
				{
					cout << "The Blue Men were hit, but were saved by their armor!!" << endl;
				}
				
				Character *chr = &blu;
				chr->armor(damage);
				chr->strength();

}
/*********************************************************************************
*Description - Armor fn 
*Fn that accepts the difference between the attack die minus the defenders roll 
*then subtracts the value from the armor, to arrive at total damage from the most 
*recent battle1  
Parameters - Damage received from battle1, minus CONST Armor
*********************************************************************************/
void Blue::armor(int d) {

	int injury;

		if(d > BL_ARMOR)
		{
			injury = d - BL_ARMOR;
		}

		else 
		{
			injury = 0;
		}

		setStrength(injury);
}

int Blue::getStrength() {
		return newStrength;

}

void Blue::setStrength(int s) {
		newStrength -= s; 
}
/*********************************************************************************
*Description - Strength fn 
*Fn that assess damage from the attack die minus the defenders roll, when the 
*character is the defender  
*********************************************************************************/
void Blue::strength() {
	
	if (getStrength() > 8)
	{
		cout << "The fight continues! Health status is: " << getStrength() << endl;
	}
		
		if((getStrength() > 5) && (getStrength() <= 8))
		{	
			cout << "The Blue Men are taking a beating, health status is: " << getStrength() << endl;
		}
		
			if((getStrength() >= 1) && (getStrength() <= 5))
			{
				cout << "The Blue Men are hanging by a thread! Health status is: " << getStrength() << endl;
			}
			
				if(getStrength() <= 0)
				{
					cout << "\nThe Blue Men have suffered a death blow and have perished in battle1. " << endl;
					setStatus(false);	
					battle1.setGoblinFactor(false);
				}
}






