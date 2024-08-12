#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"

using namespace std;

class  Item : public Object{
private:
    int health;
    int attack;
    int defense;
public:
    Item();
    Item(string, int, int, int);
    int get_health();
    int get_attack();
    int get_defense();
    void set_health(int);
    void set_attack(int);
    void set_defense(int);
    virtual bool triggerEvent(Object*)override;
};

#endif // ITEM_H_INCLUDED
