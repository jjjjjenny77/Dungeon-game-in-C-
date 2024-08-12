#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
public:
    Monster();
    Monster(string, int, int, int);
    virtual bool triggerEvent(Object*);
};


#endif // MONSTER_H_INCLUDED
