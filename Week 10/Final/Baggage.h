/************************************************************************************
 *Filename: Baggage.h
 *Name: John R Toth
 *Date: 6/1/15
 *Description: Baggage header file
 ************************************************************************************/

#ifndef BAGGAGE_H
#define BAGGAGE_H

#include "Room.h"

class Baggage: public Room {
    
protected:
    
    
public:
    Baggage();
    ~Baggage();
    void search(vector<int> &inventory);    //receives current player location, prints baggage car details
    void printDescription(bool);            //vector (bag) to hold bomb codes
    
};


#endif 