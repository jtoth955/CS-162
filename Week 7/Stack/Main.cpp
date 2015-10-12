/************************************************************************************
*Filename: Main.cpp
*Name: John R Toth
*Date: 5/22/15
*Description: Main implentation file for stack structure
*Input: User is prompted for number of ints
*Output: displays the head value and new head value after a pop() function is called
************************************************************************************/

#include <iostream> 
#include "Stack.h"

using namespace std; 

int main() {

	int num = 0, val = 0, popped = 0, peep = 0;
    
    //Stack object declaration
    Stack stack;
    
    cout << "How many numbers would you like to add to the list? " << endl;
    cin  >> num;
    
    cout << "Enter your numbers: " << endl;
    for(int a = 0; a < num; a++)
    {
        cin >> val;
        stack.push(val);
    }

    peep = stack.peek();
    cout << "Head value: " << peep << endl;

    //pop a value from the stack
    stack.pop(popped);

    peep = stack.peek();
    cout << "New head value: " << peep << endl;

	

	return 0;	
}