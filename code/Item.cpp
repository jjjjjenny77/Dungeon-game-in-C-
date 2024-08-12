#include "Item.h"

Item::Item():Object(){};
Item::Item(string name, int health, int attack, int defense):Object(name, "Item")
{
    this->health = health;
    this->attack = attack;
    this->defense = defense;
}
bool Item::triggerEvent(Object* object){
    int answer;
    Player* player = dynamic_cast<Player*>(object);
    cout << "-------------------------------------------------------"<<endl;
    cout << "So lucky! You found an supplies over there!" << endl;
    cout << "Do you want to equip " << get_name() << "(" << get_health() << ","<<get_attack() << "," << get_defense() << ")?" << endl;
    cout << "1.Yes 2.No" << endl;
    cin >> answer;
    cout << endl;
    if(answer==1){
        player->addItem(*this);
        player->increaseStates(get_health(), get_attack(), get_defense());
        return true;
    }
    else
        return false;

}
int Item::get_health(){
    return this->health;
}
int Item::get_attack(){
    return this->attack;
}
int Item::get_defense(){
    return this->defense;
}
void Item::set_health(int health){
    this->health = health;
}
void Item::set_attack(int attack){
    this->attack = attack;
}
void Item::set_defense(int defense){
    this->defense = defense;
}
