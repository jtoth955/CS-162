/************************************************************************************
 *Filename: Passenger.h
 *Name: John R Toth
 *Date: 6/1/15
 *Description: Passenger header file
 ************************************************************************************/


#ifndef PASSENGER_H
#define PASSENGER_H

#include "Room.h"
using namespace std;

class Passenger: public Room {
    
protected:
   
    
public:
    Passenger();
    ~Passenger();
    void printDescription(bool);            //receives current player location, prints passenger car details
    void search(vector<int> &inventory);    //vector (bag) to hold bomb codes

    
};


#endif