/************************************************************************************
 *Filename: Stack.cpp
 *Name: John R Toth
 *Date: 5/28/15
 *Description: Stack.cpp implementation file. A function that creates a palindrome
 ************************************************************************************/

#include "Stack.h"

#include <iostream> 
#include <stack>

using namespace std;

void Stack::runQueue(int num1, int num2, int num3, int num4, int num5) {
    
    stack<int> palStack;
    
        if(palStack.size() == 0)
            cout << "The stack is currently empty... \n" << endl;
        else
            cout << "The stack has " << palStack.size() << " elements in it." << endl;
    
    
    cout << "Loading the Palidrome values into the stack:\n" << endl;
    
        palStack.push(num1);
        cout << num1 << ", ";
    
        palStack.push(num2);
        cout << num2 << ", ";
        
        palStack.push(num3);
        cout << num3 << ", ";
        
        palStack.push(num4);
        cout << num4 << ", ";
        
        palStack.push(num5);
        cout << num5 << endl;
    
    
    cout << "\nThe stack now has " << palStack.size() << " elements in it." << endl;
    
    
}
