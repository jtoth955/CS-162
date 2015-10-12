/************************************************************************************
 *Filename: Game.h
 *Name: John R Toth
 *Date: 6/1/15
 *Description: Game header file
 ************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include <vector>
using namespace std;

class Game {
    
protected:
    Room* playerLocation;   //keeps track of player location
    Room* engineUp;         //upstairs of engine car
    Room* engineDown;       //downstairs of engine car
    vector<int> inventory;  //bag to hold players bomb codes. Max of 8
    int timesUp;            //used for time counter
    
public:
    Game();
    ~Game();
    void start();           //builds rooms/format for all cars
    void loop();            //wait for user input, do stuff
    void codes();           //display codes stored in hero's bag
    void codeCheck();       //simple function that displays messages based on
                            //number of codes acquired
};


#endif 