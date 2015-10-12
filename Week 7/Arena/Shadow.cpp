/***********************************************************************************
 *Filename: Shadow.cpp
 *Name: John R Toth
 *Date: 5/4/15
 *Description: Shadow class inherits from Character class through Polymorphism
 *Input: None
 *Output: Amount of damage given and received to other characters, as well as current
 *status of character
 ***********************************************************************************/

#include "Shadow.h"
#include "Character.h"

#include <iostream>
#include <ctime>
using namespace std;

//object declarations
Shadow shad;
Arena battle3;

const int S_ARMOR = 4;
const int S_ATTACK_DIE = 2;
const int S_ATTACK_FACE = 10;
const int S_DEFEND_DIE = 1;
const int S_DEFEND_FACE = 6;

//default constructor
Shadow::Shadow() {
    newStrength = 12;
    status = true;
}

void Shadow::setStatus(bool s) {
    status = s;
}

bool Shadow::getStatus() {
    return status;
}
/*********************************************************************************
 *Description - Attack fn Fn that passes number of die and die faces to Arena fn
 *Parameters - CONST for number of die and die faces
 *********************************************************************************/
void Shadow::attack() {
    
    int attack;
    
    battle3.setNumFaces(S_ATTACK_FACE);
    battle3.setNumDice(S_ATTACK_DIE);
    attack = battle3.Roll();
    
    cout << "The Shadow delivered a heavy blow to the opponent with a force of: " << attack << endl;
    
    battle3.setAttackRoll(attack);
    
}
/*********************************************************************************
 *Description - Defense fn
 *fn that send number of die and faces to Arena class and assesses the amount of
 *damage received
 *Parameters - Passes the amount of damage received to the the Armor fn, using
 polymorphism
 *********************************************************************************/
void Shadow::defense() {
    
    int defend, damage, impact;
    
    battle3.setNumFaces(S_DEFEND_FACE);
    battle3.setNumDice(S_DEFEND_DIE);
    defend = battle3.Roll();
    
    battle3.setDefendRoll(defend);
    damage = battle3.deathBlow();
    
    if(damage == 0)
    {
        cout << "No damage!!" << endl;
    }
    
    else if((damage > 0) && (damage < S_ARMOR))
    {
        impact = damage;
        cout << "The Shadow was injured! The injury had an impact of: -"<< impact << endl;
    }
				
				else if(damage >= S_ARMOR)
                {
                    cout << "Due to the special claok, the Shadow wasn't even there!!" << endl;
                }
    
				Character *chr = &shad;
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
void Shadow::armor(int d) {
    
    int injury;
    
    if(d < S_ARMOR)
    {
        injury = d;
    }
    
    else
    {
        injury = 0;
    }
    
    setStrength(injury);
    
}

int Shadow::getStrength() {
    return newStrength;
    
}

void Shadow::setStrength(int s) {
    newStrength -= s;
}
/*********************************************************************************
 *Description - Strength fn
 *Fn that assess damage from the attack die minus the defenders roll, when the
 *character is the defender
 *********************************************************************************/
void Shadow::strength() {
    
    if (getStrength() > 8)
    {
        cout << "The fight continues! Health status is: " << getStrength() << endl;
    }
    
    if((getStrength() > 5) && (getStrength() <= 8))
    {
        cout << "The Shadow is taking a beating, health status is: " << getStrength() << endl;
    }
    
    if((getStrength() >= 1) && (getStrength() <= 5))
    {
        cout << "The Shadow is hanging by a thread! Health status is: " << getStrength() << endl;
    }
    
				if(getStrength() <= 0)
                {
                    cout << "\nThe Shadow has suffered a death blow and has perished in battle. " << endl;
                    setStatus(false);					
                    battle3.setGoblinFactor(false);
                }
}






