#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item> commodity;
public:
    NPC();
    NPC(string, string, vector<Item>);
    void listCommodity();
    virtual bool triggerEvent(Object*);

    /* Set & Get function*/
    void set_script(string);
    void set_commodity(vector<Item>);
    string get_script();
    vector<Item> get_commodity();
};


#endif // NPC_H_INCLUDED
