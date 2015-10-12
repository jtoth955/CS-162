/***********************************************************************************
 *Filename: Goblin.cpp
 *Name: John R Toth
 *Date: 5/4/15
 *Description: Goblin class inherits from Character class through Polymorphism
 *Input: None
 *Output: Amount of damage given and received to other characters, as well as current
 *status of character
 ***********************************************************************************/

#include "Goblin.h"
#include "Character.h"

#include <iostream>
#include <ctime>
using namespace std;

//object declarations
Goblin gob;
Arena battle4;

const int G_ARMOR = 3;
const int G_ATTACK_DIE = 2;
const int G_ATTACK_FACE = 6;
const int G_DEFEND_DIE = 1;
const int G_DEFEND_FACE = 6;

//default constructor
Goblin::Goblin() {
    newStrength = 8;
    status = true;
}

void Goblin::setStatus(bool s) {
    status = s;
}

bool Goblin::getStatus() {
    return status;
}
/*********************************************************************************
 *Description - Attack fn Fn that passes number of die and die faces to Arena fn
 *Parameters - CONST for number of die and die faces
 *********************************************************************************/
void Goblin::attack() {
    
    int attack;
    
    battle4.setNumFaces(G_ATTACK_FACE);
    battle4.setNumDice(G_ATTACK_DIE);
    attack = battle4.Roll();
    
    if(attack == 12)
    {
        if(battle4.getGoblinFactor() == false)
        {
            battle4.setGoblinFactor(true);
        }
        
    }
    
    cout << "The Goblin delivered a heavy blow to the opponent with a force of: " << attack << endl;
    
    battle4.setAttackRoll(attack);
    
}
/*********************************************************************************
 *Description - Defense fn
 *fn that send number of die and faces to Arena class and assesses the amount of
 *damage received
 *Parameters - Passes the amount of damage received to the the Armor fn, using
 polymorphism
 *********************************************************************************/
void Goblin::defense() {
    
    int defend, damage, impact;
    
    battle4.setNumFaces(G_DEFEND_FACE);
    battle4.setNumDice(G_DEFEND_DIE);
    defend = battle4.Roll();
    
    battle4.setDefendRoll(defend);
    damage = battle4.deathBlow();
    
    if(damage == 0)
    {
        cout << "No damage!!" << endl;
    }
    
    else if(damage > G_ARMOR)
    {
        impact = damage - G_ARMOR;
        cout << "The Goblin was injured! The injury had an impact of: -"<< impact << endl;
    }
				
				else if((damage > 0) && (damage <= G_ARMOR))
                {
                    cout << "The Goblin was hit, but was saved by their armor!!" << endl;
                }
    
				Character *chr = &gob;
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
void Goblin::armor(int d) {
    
    int injury;
    
    if(d > G_ARMOR)
    {
        injury = d - G_ARMOR;
    }
    
    else
    {
        injury = 0;
    }
    
    setStrength(injury);
    
}

int Goblin::getStrength() {
    return newStrength;
    
}

void Goblin::setStrength(int s) {
    newStrength -= s;
}
/*********************************************************************************
 *Description - Strength fn
 *Fn that assess damage from the attack die minus the defenders roll, when the
 *character is the defender
 *********************************************************************************/
void Goblin::strength() {
    
    if (getStrength() > 8)
    {
        cout << "The fight continues! Health status is: " << getStrength() << endl;
    }
    
    if((getStrength() > 5) && (getStrength() <= 8))
    {
        cout << "The Goblin is taking a beating, health status is: " << getStrength() << endl;
    }
    
    if((getStrength() >= 1) && (getStrength() <= 5))
    {
        cout << "The Goblin is hanging by a thread! Health status is: " << getStrength() << endl;
    }
    
				if(getStrength() <= 0)
                {
                    cout << "\nThe Goblin has suffered a death blow and has perished in battle. " << endl;
                    setStatus(false);					
                }
}






