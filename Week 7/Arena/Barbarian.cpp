/***********************************************************************************
 *Filename: Barbarian.cpp
 *Name: John R Toth
 *Date: 5/4/15
 *Description: Barbarian class inherits from Character class through Polymorphism
 *Input: None
 *Output: Amount of damage given and received to other characters, as well as current
 *status of character
 ***********************************************************************************/

#include "Character.h"
#include "Barbarian.h"
#include "Arena.h"

#include <iostream>
#include <ctime>
using namespace std;

//object declarations
Barbarian barb;
Arena battle;

const int B_ARMOR = 0;
const int B_DIE_FACE = 6;
const int B_NUM_DIE = 2;

//default constructor
Barbarian::Barbarian() {
    newStrength = 12;
    status = true;
}

void Barbarian::setStatus(bool s) {
    status = s;
}

bool Barbarian::getStatus() {
    return status;
}
/*********************************************************************************
 *Description - Attack fn Fn that passes number of die and die faces to Arena fn
 *Parameters - CONST for number of die and die faces
 *********************************************************************************/
void Barbarian::attack() {
    
    int attack;
    
    battle.setNumFaces(B_DIE_FACE);
    battle.setNumDice(B_NUM_DIE);
    attack = battle.Roll();
    
    cout << "The Barbarian delivered a heavy blow to the opponent with a force of: " << attack << endl;
    
    battle.setAttackRoll(attack);
    
}
/*********************************************************************************
 *Description - Defense fn
 *fn that send number of die and faces to Arena class and assesses the amount of
 *damage received
 *Parameters - Passes the amount of damage received to the the Armor fn, using
 polymorphism
 *********************************************************************************/
void Barbarian::defense() {
    
    int defend, damage, impact;
    
    battle.setNumFaces(B_DIE_FACE);
    battle.setNumDice(B_NUM_DIE);
    defend = battle.Roll();
    
    battle.setDefendRoll(defend);
    damage = battle.deathBlow();
    
    if(damage == 0)
    {
        cout << "No damage!!" << endl;
    }
    
    else if(damage > B_ARMOR)
    {
        impact = damage - B_ARMOR;
        cout << "The Barbarian was injured! The injury had an impact of: -"<< impact << endl;
    }
				
				else if((damage > 0) && (damage <= B_ARMOR))
                {
                    cout << "The Barbarian was hit, but was saved by their armor!!" << endl;
                }
    
				Character *chr = &barb;
				chr->armor(damage);
				chr->strength();
    
}
/*********************************************************************************
 *Description - Armor fn
 *Fn that accepts the difference between the attack die minus the defenders roll
 *then subtracts the value from the armor, to arrive at total damage from the most
 *recent battle
 Parameters - Damage received from battle, minus CONST Armor
 *********************************************************************************/
void Barbarian::armor(int d) {
    
    int injury;
    
    if(d > B_ARMOR)
    {
        injury = d - B_ARMOR;
    }
    
    else
    {
        injury = 0;
    }
    
    setStrength(injury);
    
}

int Barbarian::getStrength() {
    return newStrength;
    
}

void Barbarian::setStrength(int s) {
    newStrength -= s;
}
/*********************************************************************************
 *Description - Strength fn
 *Fn that assess damage from the attack die minus the defenders roll, when the
 *character is the defender
 *********************************************************************************/
void Barbarian::strength() {
    
    if (getStrength() > 8)
    {
        cout << "The fight continues! Health status is: " << getStrength() << endl;
    }
    
    if((getStrength() > 5) && (getStrength() <= 8))
    {
        cout << "The Barbarian is taking a beating, health status is: " << getStrength() << endl;
    }
    
    if((getStrength() >= 1) && (getStrength() <= 5))
    {
        cout << "The Barbarian is hanging by a thread! Health status is: " << getStrength() << endl;
    }
    
				if(getStrength() <= 0)
                {
                    cout << "\nThe Barbarian has suffered a death blow and has perished in battle. " << endl;
                    setStatus(false);					
                    battle.setGoblinFactor(false);
                }
}