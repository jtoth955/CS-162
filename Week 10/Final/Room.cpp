/***********************************************************************************
 *Filename: Room.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description:
 *Input: None
 *Output: None
 ***********************************************************************************/

#include "Room.h"
#include <cstdlib>

Room::Room(){
    setUpstairs(NULL);
    setDownstairs(NULL);
    setLeft(NULL);
    setRight(NULL);
}

Room::~Room(){
    
}
Room* Room::getLeft(){
    return left;
}
Room* Room::getRight() {
    return right;
}

Room* Room::getUpstairs() {
    return upstairs;
}
Room* Room::getDownstairs() {
    return downstairs;
}
void Room::setLeft(Room* r) {
    left = r;
}
void Room::setRight(Room* r){
    right = r;
}
void Room::setUpstairs(Room* r){
    upstairs = r;    
}
void Room::setDownstairs(Room* r){
    downstairs = r;
}