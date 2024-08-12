#include "Player.h"

Player::Player():GameCharacter(){}

Player::Player(string name,int currentHealth, int attack, int defense):GameCharacter(name, "Player", currentHealth, attack, defense){
    set_maxHealth(currentHealth);
    set_currentHealth(currentHealth);
    set_attack(attack);
    set_defense(defense);
}
bool Player::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout<<"Your name is "<<get_name()<<endl;
    cout<<"Your Health: "<<get_currentHealth()<<endl;
    cout<<"Your Attack "<<get_attack()<<endl;
    cout<<"Your Defense "<<get_defense()<<endl;
    cout<<"You are in room "<<currentRoom->get_index()<<endl;
}

void Player::addItem(Item item){
    inventory.push_back(item);
 }
void Player::increaseStates(int health, int attack,int defense){
    set_currentHealth(get_currentHealth()+health);
    set_attack(get_attack()+attack);
    set_defense(get_defense()+defense);
}
void Player::set_currentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}
void Player::set_previousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}
void Player::set_inventory(vector<Item> inventory){
    this->inventory = inventory;
}
Room* Player::get_currentRoom(){
    return this->currentRoom;
}
Room* Player::get_previousRoom(){
    return this->previousRoom;
}
vector<Item> Player::get_inventory(){
    return this->inventory;
}
void Player::changeRoom(Room* newRoom){
    this->previousRoom = currentRoom;
    this->currentRoom = newRoom;
}
