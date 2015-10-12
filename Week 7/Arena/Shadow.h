/************************************************************************************
 *Filename: Shadow.hpp
 *Name: John R Toth
 *Date: 5/4/15
 *Description: Shadow header file
 ************************************************************************************/

#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Character.h"
#include "Arena.h"

#include <iostream>
using namespace std;


class Shadow: public Character
{
protected:
    //member variables
    int newStrength;
    bool status;
    
    
public:
    //default constructor
    Shadow();
    
    //mutator fn that sets characters status
    void setStatus(bool);
    //setStatus - sets the status of the Shadow
    //@param bool - status of Shadow
    
    //Accessor fn that gets characters status
    bool getStatus();
    
    //accessor fn getStrength
    int getStrength();
    
    //mutator fn setStregth
    void setStrength(int);
    //setStrength - sets the strength of the Shadow
    //@param int - strength of Shadow
    
    
    void attack();
    void defense();
    void armor(int);
    void strength();
    
};
#endif