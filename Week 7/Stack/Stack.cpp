/************************************************************************************
*Filename: Stack.cpp
*Name: John R Toth
*Date: 5/22/15
*Description: Stack.cpp implementation file
************************************************************************************/

#include "Stack.h"

#include <iostream> 
using namespace std; 

Stack::Stack() {
	top = NULL;
}
void Stack::push(int num) {
	top = new LifoNode(num, top); 
}
int Stack::peek() {

	return top->value;
}
void Stack::pop(int &num) {
	LifoNode *temp;

	if(isEmpty())
	{
		cout << "Stack is empty" << endl;
		return; 
	}
	else
	{
		num = top->value; 
		temp = top; 
		top = top->next;
		delete temp;
	}
}
bool Stack::isEmpty() const {
	if(!top)
		return true; 
	else 
		return false; 
}