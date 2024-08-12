#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects;
public:
    Room();
    Room(bool, int, vector<Object*>);
    bool clearObject(Object*);
    bool buyItem(int);

    void add(bool,int,vector<Object*>);
    void set_upRoom(Room*);
    void set_downRoom(Room*);
    void set_leftRoom(Room*);
    void set_rightRoom(Room*);
    void set_isExit(bool);
    void set_index(int);
    void set_objects(vector<Object*>);
    bool get_isExit();
    int get_index();
    vector<Object*> get_objects();
    Room* get_upRoom();
    Room* get_downRoom();
    Room* get_leftRoom();
    Room* get_rightRoom();
};

#endif // ROOM_H_INCLUDED
