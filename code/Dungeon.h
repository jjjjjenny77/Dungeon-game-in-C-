#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Record.h"

using namespace std;

class Dungeon{
private:
    Player player;
    vector<Room> rooms;
public:
    Dungeon();
    void createPlayer();

    void createMap();

    void handleMovement();

    void handleEvent(Object*);

    void startGame();

    void chooseAction(vector<Object*>);

    bool checkGameLogic();

    void runDungeon();
};

#endif // DUNGEON_H_INCLUDED
