#include<iostream>
#include<string>
#include<vector>
#include "Dungeon.h"
#include "Item.h"
#include "GameCharacter.h"
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include <fstream>
using namespace std;
int main(){
    Dungeon start = Dungeon();
    start.runDungeon();
    return 0;
}
