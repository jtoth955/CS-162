/************************************************************************************
*Filename: Stack.h
*Name: John R Toth
*Date: 5/22/15
*Description: Stack header file
************************************************************************************/

#ifndef STACK_H
#define STACK_H
using namespace std; 

class Stack
{
private:                                //I referenced our text in designing this 
    class LifoNode                      //structure, re: Dynamic Stacks 
    {
        friend class Stack;
        int value; 
        LifoNode *next;

       LifoNode(int val, LifoNode *next1 = 0)
        {
          value = val;
          next = next1;
        }
    };
    LifoNode *top;

public: 
    Stack();
    int peek(); 
    void push(int);
    void pop(int &);
    bool isEmpty() const;

};
#endif

