/************************************************************************************
 *Filename: Character.hpp
 *Name: John R Toth
 *Date: 5/4/15
 *Description: Character header file
 ************************************************************************************/

#ifndef Character_h
#define Character_h

#include <iostream>
using namespace std;


class Character
{
    
public:
    virtual void attack()=0;
    virtual void defense()=0;
    virtual void armor(int)=0;
    virtual void strength()=0;
    
};
#endif

