#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
public:
    Player();
    Player(string, int, int, int);
    void addItem(Item);
    void increaseStates(int,int,int);
    void changeRoom(Room*);
    virtual bool triggerEvent(Object*);

    void set_currentRoom(Room*);
    void set_previousRoom(Room*);
    void set_inventory(vector<Item>);
    Room* get_currentRoom();
    Room* get_previousRoom();
    vector<Item> get_inventory();
};

#endif // PLAYER_H_INCLUDED
