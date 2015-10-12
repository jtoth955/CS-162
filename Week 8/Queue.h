/************************************************************************************
 *Filename: Queue.h
 *Name: John R Toth
 *Date: 5/28/15
 *Description: Queue header file
 ************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

class Queue {

public:

    Queue();
    ~Queue(); 
    int roll(float percent);
    void addPercent();
    void remPercent();
    void add(int);
    void remove();
    void average();
    
private:
    int numDice;
    int numFaces;
    
};

#endif
