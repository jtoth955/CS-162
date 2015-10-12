/***********************************************************************************
 *Filename: Baggage.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description:
 *Input: None
 *Output: Baggage car details, results of random die roll
 ***********************************************************************************/

#include "Baggage.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Baggage::Baggage() {
    numDice = 1;
    numFaces = 10;
}

Baggage::~Baggage(){
}

void Baggage::printDescription(bool up) {
    
    if(up == true)
    {
        cout << "\nYou're currently on the upper level of the Baggage Car. Alike the lower level, there "
        "are bags everywhere. On the left and right, bags are stacked in an orderly fashion.  " << endl;
    }
    else
    {
       cout << "\nYou're currently on the lower level of the Baggage Car. Since the train is packed, there "
       "are bags everywhere. Larger luggage and baggage items are reserved for the lower level, so you "
        "will not have to search as many objects to find a code. " << endl;
    }

}
void Baggage::search(vector<int> &inventory) {
    
    int total = 0, chance = 0;
    
    cout << "\nYou begin searching the baggage train... " << endl;
    
    
    
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
    
    if((chance >= 1) && (chance <= 4))
    {
        cout << "\nAHA! You've found a code and begin entering it!!\n" << endl;
        cout << "Code accepted! You successfully entered the bomb diffusal code!\n" << endl;
        inventory.push_back(total);
    }
    
    else if(chance == 5)
    {
        cout << "\nSearch was unsuccessful, look elsewhere! \n" << endl;
    }
    
    return;
    
    
}
