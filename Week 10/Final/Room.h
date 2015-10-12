/************************************************************************************
 *Filename: Room.h
 *Name: John R Toth
 *Date: 6/1/15
 *Description: Room header file
 ************************************************************************************/

#ifndef ROOM_H
#define ROOM_H

#include <vector>
using namespace std;

class Room {

protected:
    Room* left;
    Room* right;
    Room* upstairs;
    Room* downstairs;
    int numDice;
    int numFaces;

public:
    Room();
    virtual ~Room() = 0;
    virtual Room* getLeft();
    virtual Room* getRight();
    virtual Room* getUpstairs();
    virtual Room* getDownstairs();
    virtual void setLeft(Room* r);
    virtual void setRight(Room* r);
    virtual void setUpstairs(Room* r);
    virtual void setDownstairs(Room* r);
    virtual void printDescription(bool up) = 0;
    virtual void search(vector<int> &inventory)= 0;
    

};

#endif 