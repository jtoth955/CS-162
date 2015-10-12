/************************************************************************************
 *Filename: Game.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description:
 *Input: User defines the action they would like to take, based on the menu consisting
 *of 5 user options.
 *Output: Default constructor creates train. Train consists of 5 total cars (1 engine,
 *2 baggage cars, 2 passenger cars). Each car has an upper and lower level. Game.cpp
 *also houses the menu of options so the user can navigate the game. Lastly, Game.cpp
 *displays the bomb codes that are in the users bag as well as a simple function that 
 *advises the user when they have 4 and 7 total codes in their bag.
 ************************************************************************************/

#include "Game.h"
#include "Engine.h"
#include "Baggage.h"
#include "Passenger.h"

#include <iostream>
using namespace std;

Engine engine;

/***********************************************************************************
Description: default constructor constructs the train upon starting game
***********************************************************************************/

Game::Game() {
    timesUp = 90;
    
    engineUp = new Engine();
    engineDown = new Engine();
    engineUp->setDownstairs(engineDown);
    engineDown->setUpstairs(engineUp);
    Room* tempUp;
    Room* tempDown;
    
    
    tempUp = new Baggage();
    tempDown = new Baggage();
    tempUp->setDownstairs(tempDown);
    tempDown->setUpstairs(tempUp);
    tempUp->setLeft(engineUp);
    tempDown->setLeft(engineDown);
    engineUp->setRight(tempUp);
    engineDown->setRight(tempDown);
    Room* nextUp;
    Room* nextDown;
    
    
    nextUp = new Passenger();
    nextDown = new Passenger();
    nextUp->setDownstairs(nextDown);
    nextDown->setUpstairs(nextUp);
    nextUp->setLeft(tempUp);
    nextDown->setLeft(tempDown);
    tempUp->setRight(nextUp);
    tempDown->setRight(nextDown);
    tempUp = nextUp;
    tempDown = nextDown;
    
    
    nextUp = new Passenger();
    nextDown = new Passenger();
    nextUp->setDownstairs(nextDown);
    nextDown->setUpstairs(nextUp);
    nextUp->setLeft(tempUp);
    nextDown->setLeft(tempDown);
    tempUp->setRight(nextUp);
    tempDown->setRight(nextDown);
    tempUp = nextUp;
    tempDown = nextDown;
    
    
    nextUp = new Baggage();
    nextDown = new Baggage();
    nextUp->setDownstairs(nextDown);
    nextDown->setUpstairs(nextUp);
    nextUp->setLeft(tempUp);
    nextDown->setLeft(tempDown);
    tempUp->setRight(nextUp);
    tempDown->setRight(nextDown);
    
}

Game::~Game() {
    
    Room* nextUp = engineUp->getRight();
    Room* nextDown = engineDown->getRight();
    
    while(engineUp != NULL)
    {
        nextUp = engineUp->getRight();
        delete engineUp;
        engineUp = nextUp;
    }
    
    while(engineDown != NULL)
    {
        nextDown = engineDown->getRight();
        delete engineDown;
        engineDown = nextDown;
    }
    
}
void Game::start() {
    
    //game begins with hero being dropped into the upper level of the engine room
    playerLocation = engineUp;
    
    loop(); 
}
void Game::loop() {
    
    int choice = 0;
    
    
    cout << "----\n\n" << endl;
    cout << "\n                       Runaway Train\n"                                    << endl;
    
    
    do {
        cout << "Time left on bomb: " << timesUp << " minutes... " << endl << endl;
        cout << "What is your move?\n" << endl;
        
        cout << "1. Move Upstairs\n";
        cout << "2. Move Downstairs\n";
        cout << "3. Move to next train\n";
        cout << "4. Move back a train\n";
        cout << "5. Search current car\n";
        
        cin  >> choice;
        
        //use the menu selection to execute the correct set of actions
        if(choice == 1)
            //Search upstairs
        {
            if(playerLocation->getUpstairs() == NULL)
            {
                cout << "\nYou are already upstairs! You just wasted an additional 5 minutes!\n" << endl;
                timesUp -= 5;
            }
            else
            {
                playerLocation = playerLocation->getUpstairs();
                cout << "\nYou are now upstairs, start searching!\n" << endl;
            }
        }
        
        else if(choice == 2)
            //search downstairs
        {
            if(playerLocation->getDownstairs() == NULL)
            {
                cout << "\nYou are already downstairs! You just wasted an additional 5 minutes!\n" << endl;
                timesUp -= 5;
            }
            else
            {
                playerLocation = playerLocation->getDownstairs();
                cout << "\nYou are now downstairs!\n" << endl;
            }
        }
        
        else if(choice == 3)
            //move forward to next train
        {
            if(playerLocation->getRight() == NULL)
            {
                cout << "\nYou're at the end of the train, go back! You just wasted an additionl 5 minutes!\n" << endl;
                timesUp -= 5;
            }
            else
            {
                playerLocation = playerLocation->getRight();
                cout << "\nYou have moved to the next train, now search before the time runs out!\n" << endl;
            }
        }
        else if(choice == 4)
            //move backward to previous train
        {
            if(playerLocation->getLeft() == NULL)
            {
                cout << "\nYou're at the engine! You just wasted an additional 5 minutes!\n" << endl;
                timesUp -= 5;
            }
            else
            {
                playerLocation = playerLocation->getLeft();
                cout << "\nYou are now in the previous train. Hurry, time is running out!\n" << endl;
            }
        }
        else if(choice == 5)
            //search current car for bomb codes
        {
            playerLocation->printDescription(playerLocation->getUpstairs() == NULL);
            playerLocation->search(inventory);
            
            
        }
        else if(choice > 5)
        {
            cout <<"\nPay attention!! The valid choices are 1 - 5.\n" << endl;
        }
        
        timesUp -= 5;
        
        codes();
        codeCheck();
        
    }while((choice < 6) && (timesUp > 0) && (inventory.size() < 8));
    
    
    
        if(timesUp <= 0)
            cout << "\nKABOOOOM! You did not defuse the bomb in time... " << endl;
        
            if(inventory.size() == 8)
                cout << "You have saved the day!!! The bomb has been diffused and the train is slowing! " << endl;
    
    
    
    cout << "\nGAME OVER " << endl;
    
    
}
void Game::codes() {

    if((inventory.size() > 0) && (inventory.size() < 8))
    {
    cout << "Current bomb codes: " << endl;
        for(int x = 0; x < inventory.size(); x++ )
        {
            cout << inventory[x] << " ";
        }
    
        cout << endl << endl;
    }
    else if(inventory.size() == 8)
    {
        cout << "Final bomb codes that stopped the bomb: " << endl;
        for(int x = 0; x < inventory.size(); x++ )
        {
            cout << inventory[x] << " ";
        }
        
        cout << endl << endl;
    }

    else
    {
        cout << "\nYou haven't collected any codes yet, HURRY!\n" << endl;
    }

}
void Game::codeCheck() {
    
    if(inventory.size() == 7)
        cout << "\nYou only need one more code, HURRY!\n" << endl;
    
    if(inventory.size() == 4)
        cout << "\nYou've collected half the codes, find 4 more!\n" << endl;
    
}







