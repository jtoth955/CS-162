/***********************************************************************************
 *Filename: Passenger.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description:
 *Input: None
 *Output: Passenger car details, results of random die roll
 ***********************************************************************************/

#include "Passenger.h"
#include <cstdlib>
#include <iostream>

using namespace std;


Passenger::Passenger(){
    numDice = 1;
    numFaces = 10;
}
Passenger::~Passenger(){
    
}
void Passenger::printDescription(bool up) {
    
    if(up == true)
    {
        cout << "\nYour currently on the upper level of the Passenger car. The upstairs of the passenger car is similar to the lower level, just fewer seats. Since the upper level is typically less busy, this may be a great place to search. " << endl;
    }
    else
    {
        cout << "\nYour currently on the lower level of the Passenger car. The downstairs area is pretty busy, be careful not to spook the passengers while searching, you don't wnat them to know something is wrong with the train! " << endl;
    }

    
}
void Passenger::search(vector<int> &inventory) {
    
    int total = 0, chance = 0;
    
    cout << "\nYou begin searching the passenger train... " << endl;
    
    
    
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
        cout << "\nAHA! You've found a code and begin entering it!!\n" << endl;
        cout << "Code accepted! You successfully entered the bomb diffusal code!\n" << endl;
        inventory.push_back(total);
    }

    else if(chance == 1)
    {
        cout << "\nSearch unsuccessful, look elsewhere! \n" << endl;
    }
    
    return;
}
