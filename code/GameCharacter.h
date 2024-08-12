#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter:public Object
{
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
public:
    GameCharacter();
    GameCharacter(string, string, int, int, int);
    bool checkisDead();
    int takeDamage(int);
    void set_maxHealth(int);
    void set_currentHealth(int);
    void set_attack(int);
    void set_defense(int);
    int get_maxHealth();
    int get_currentHealth();
    int get_attack();
    int get_defense();
};

#endif // GAMECHARACTER_H_INCLUDED
