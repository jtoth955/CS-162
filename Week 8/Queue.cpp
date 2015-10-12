/************************************************************************************
 *Filename: Queue.cpp
 *Name: John R Toth
 *Date: 5/28/15
 *Description: Queue.cpp implementation file
 ************************************************************************************/

#include "Queue.h"
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> buffQ;
deque<int>::iterator iter;

Queue::Queue() {
    numDice = 1;
    numFaces = 4;
}
Queue::~Queue() {

}

int Queue::roll(float percent) {

    int total = 0, chance = 0;
 
    
    for (int i = 0; i < numDice; i++)
    {
        total = total+rand()%numFaces+1;
    }

    //taz, this is for your reference, to make grading easier
    cout <<"\nThis is the die roll for total: " << total << endl;
    
        //loop again to determine new random number, which will be used to determine if value is added
        //or removed from queue
    
        for (int j = 0; j < 1; j++)
        {
            chance = chance+rand()%5+1;
        }
    //taz, this is for your reference, to make grading easier
    cout <<"This is the die roll for chance: " << chance << endl << endl;
    
    
    //determine randomly whether or not a value will be added or removed, based on user input percentage
    
    if((percent <= 25.0) && (chance == 1))
            return total;
 
        else if(((percent > 25.0) && (percent <= 50.0)) && ((chance == 1) || (chance == 2)))
               return total;

            else if(((percent > 50.0) && (percent <= 75.0)) && ((chance >= 2) && (chance <= 4)))
                    return total;
            
                else if(((percent > 75.0) && (percent < 100.0)) && ((chance >= 1) && (chance <= 4)))
                        return total;
                
                    else if(((percent == 100.0)) && ((chance >= 1) || (chance <= 5)))
                        return total;
    

return 0;

}
void Queue::addPercent() {
    
    float addPercent = 0.0;
    int num = 0;
    
    cout << "Enter a percentage: "<< endl;
    cin  >> addPercent;
    
    num = roll(addPercent);
    
    if(num != 0)
        add(num);
    else
        cout << "\nNo value passed to queue due to percentage.\n" << endl;
    
}
void Queue::remPercent() {

    float remPercent = 0.0;
    int num = 0;
    
    cout << "Enter a removal percentage: "<< endl;
    cin  >> remPercent;

    num = roll(remPercent);

    if(num != 0)
        remove();
    else
        cout << "\nNo value passed to queue due to percentage. \n" << endl;

}
void Queue::add(int val) {
    
    buffQ.push_back(val);
    
    cout << "The Queue container now has " << buffQ.size() << " items in it.\n" << endl;
    
}
void Queue::remove() {
   
    if(buffQ.empty())
       {
           cout << "The container is empty, no further items can be removed " << endl;
           return;
       }
       
    else
        buffQ.pop_front();
    
    cout << "The Queue container now has " << buffQ.size() << " items in it. " << endl;

}
void Queue::average() {
    
    float average = 0.0;
    int count = 0;
    
    //display message if there are no values in Queue
    if(buffQ.size() == 0)
    {
        cout << "The queue is currently empty. " << endl;
        return;
    }
    else
        cout << "The queue now contains the following values: ";
    
        for(iter = buffQ.begin(); iter != buffQ.end(); iter++)
            {
                cout << *iter << " ";
                average += iter[count];
            }
                    average /= buffQ.size();
                    cout << "\nThe Queue's average is: " << average << endl << endl;
    
}






