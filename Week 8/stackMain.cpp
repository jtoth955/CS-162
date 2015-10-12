/*************************************************************************************
 *Filename: stackMain.cpp
 *Name: John R Toth
 *Date: 5/22/15
 *Description: Main.cpp passes 5 integer values to runQueue function in the Stack class
 *************************************************************************************/

#include <iostream>
#include "Stack.h"

#include <stack>
using namespace std;

int main() {
    
    Stack palindrome;
    
    palindrome.runQueue(1, 2, 3, 2, 1);
    
    return 0;
}
