/************************************************************************************
 *Filename: Main.cpp
 *Name: John R Toth
 *Date: 5/22/15
 *Description: Stack.cpp implementation file
 ************************************************************************************/

#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    Queue container;
    
    char response = ' ';
    unsigned seed;
    seed = (time(0));
    srand(seed);
    
    do  {
        
        container.addPercent();
        container.remPercent();
        container.average();
        
        cout << "Would you like to continue? Y/N " << endl;
        cin  >> response;
    }
     while((response == 'Y') || (response == 'y'));
    
    
    return 0;
}
