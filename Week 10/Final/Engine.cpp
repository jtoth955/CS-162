/***********************************************************************************
 *Filename: Engine.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description:
 *Input: None
 *Output: Engine car details, results of random die roll
 ***********************************************************************************/

#include "Engine.h"
#include <cstdlib>
#include <iostream> 

using namespace std;

Engine::Engine(){
    numDice = 1;
    numFaces = 10;
}

Engine::~Engine(){
    
}
void Engine::printDescription(bool up) {
    
    if(up == true)
    {
        cout << "\nThis is the upper level of the engine room. It's hot, and very confined. As the FBI advised when they dropped you off, the best bet would be to do a quick search of this area, then move to the lower level. " << endl;
    }
    else
    {
        cout << "\nThis is the lower level of the engine room, it's a little more open then the upper level, but is very dark. Be careful while searching, there are many objects that are VERY hot! " << endl;
    }

    
}
void Engine::search(vector<int> &inventory) {
    
    int total = 0, chance = 0;
    
    cout << "\nYou begin searching the engine train... " << endl;
    cout << "\nAHA! You've found a code and begin entering it!!\n" << endl;
    
    
    for (int i = 0; i < numDice; i++)
    {
        total = total+rand()%numFaces+1;
    }
    
    //loop again to determine new random number, which will be used to determine if value is added
    //or removed from queue
    
    for (int j = 0; j < 1; j++)
    {
        chance = chance+rand()%5+1;
    }
    
    //determine randomly whether or not a value will be added or removed, based on user input percentage
    
    if((chance >= 2) && (chance <= 5))
    {
        cout << "Code accepted! You successfully entered the bomb diffusal code!\n" << endl;
        inventory.push_back(total);
    }
    
    else if(chance == 1)
    {
        cout << "\nYou entered a bad code! Luckily, the bomb didn't explode!\n" << endl;
    }

return;

}
