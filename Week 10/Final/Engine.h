/************************************************************************************
 *Filename: Engine.h
 *Name: John R Toth
 *Date: 6/1/15
 *Description: Engine header file
 ************************************************************************************/


#ifndef ENGINE_H
#define ENGINE_H

#include "Room.h"
#include <vector>

using namespace std;

class Engine: public Room {
    
protected:
    
    
public:
    Engine();
    ~Engine();
    void printDescription(bool);            //receives current player location, prints engine car details
    void search(vector<int> &inventory);    //vector (bag) to hold bomb codes
    
};


#endif
