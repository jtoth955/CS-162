/***********************************************************************************
 *Filename: Main.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description:
 *Input: None
 *Output: Opening message of game, informing the user what the point of the game is
 ***********************************************************************************/


#include <iostream>
#include <cstdlib>
#include "Game.h"

int main() {
    Game game;
    
    unsigned seed;
    seed = (time(0));
    srand(seed);
    
    cout << "                       Runaway Train\n"                                    << endl;
    
    cout << "You're on a passenger train, traveling 50 mph. The train is full of passengers.\n" << endl;
    cout << "There is a bomb on the train and you have 90 minutes to find and diffuse it, before it blows! " << endl;
    cout << "\nFind the 8 bomb diffusal codes, they are each located somewhere on the train.\n" << endl;
    cout << "You will be helicoptered in by the FBI, you will enter the speeding train in the engine room.\n"<< endl;
    cout << "You may traverse the train, anyway you like, but must find the bomb codes prior to the ";
    cout << "villains detinating the bomb!\n" << endl;
    cout << "Keep in mind, the train has 2 levels and codes can be found anywhere.\n"<< endl;
    cout << "Good luck! " << endl;
    
    
    
    game.start();
    
    
    return 0;
}
