/***********************************************************************************
 *Filename: Reptile.cpp
 *Name: John R Toth
 *Date: 5/4/15
 *Description: Reptile class inherits from Character class through Polymorphism
 *Input: None
 *Output: Amount of damage given and received to other characters, as well as current
 *status of character
 ***********************************************************************************/

#include "Reptile.h"

#include <iostream>
#include <ctime>
using namespace std;

//object declarations
Reptile rep;
Arena battle2;

const int R_ARMOR = 7;
const int R_ATTACK_DIE = 3;
const int R_ATTACK_FACE = 6;
const int R_DEFEND_DIE = 1;
const int R_DEFEND_FACE = 6;

//default constructor
Reptile::Reptile() {
    newStrength = 18;
    status = true;
}

void Reptile::setStatus(bool s) {
    status = s;
}

bool Reptile::getStatus() {
    return status;
}
/*********************************************************************************
 *Description - Attack fn Fn that passes number of die and die faces to Arena fn
 *Parameters - CONST for number of die and die faces
 *********************************************************************************/
void Reptile::attack() {
    
    int attk;
    
    battle2.setNumFaces(R_ATTACK_FACE);
    battle2.setNumDice(R_ATTACK_DIE);
    attk = battle2.Roll();
    
    battle2.setAttackRoll(attk);
    
    cout << "The Reptile People delivered a heavy blow to the opponent with a force of: " << attk << endl;
    
    
    
}
/*********************************************************************************
 *Description - Defense fn
 *fn that send number of die and faces to Arena class and assesses the amount of
 *damage received
 *Parameters - Passes the amount of damage received to the the Armor fn, using
 polymorphism
 *********************************************************************************/
void Reptile::defense() {
    
    int defend, damage, impact;
    
    battle2.setNumFaces(R_DEFEND_FACE);
    battle2.setNumDice(R_DEFEND_DIE);
    defend = battle2.Roll();
    
    battle2.setDefendRoll(defend);
    damage = battle2.deathBlow();
    
    if(damage == 0)
    {
        cout << "No damage!!" << endl;
    }
    
    else if(damage > R_ARMOR)
    {
        impact = damage - R_ARMOR;
        cout << "The Reptile People were injured! Because of armor, it only had an impact of: -"<< impact << endl;
    }
    
				else if((damage > 0) && (damage <= R_ARMOR))
                {
                    cout << "The Reptile People were hit, but were saved by their armor!!" << endl;
                }
    
				Character *chr = &rep;
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
void Reptile::armor(int d) {
    
    int injury;
    
    if(d > R_ARMOR)
    {
        injury = d - R_ARMOR;
    }
    
    else
    {
        injury = 0;
    }
    
    setStrength(injury);
    
}

int Reptile::getStrength() {
    return newStrength;
    
}

void Reptile::setStrength(int s) {
    newStrength -= s;
}
/*********************************************************************************
 *Description - Strength fn
 *Fn that assess damage from the attack die minus the defenders roll, when the
 *character is the defender
 *********************************************************************************/
void Reptile::strength() {
    
    if (getStrength() > 8)
    {
        cout << "The fight continues! Health status is: " << getStrength() << endl;
    }
    
    if((getStrength() > 5) && (getStrength() <= 8))
    {
        cout << "The Reptile People are taking a beating, health status is: " << getStrength() << endl;
    }
    
    if((getStrength() >= 1) && (getStrength() <= 5))
    {
        cout << "The Reptile People are hanging by a thread! Health status is: " << getStrength() << endl;
    }
				
				if(getStrength() <= 0)
                {
                    cout << "\nThe Reptile People have suffered a death blow and have perished in battle. " << endl;
                    setStatus(false);
                    battle2.setGoblinFactor(false);
                    
                }
}






