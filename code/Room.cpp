#include "Room.h"

Room::Room(){

}
Room::Room(bool isExit, int index, vector<Object*> objects){
    this->isExit = isExit;
    this->index = index;
    this->objects = objects;
}

void Room::set_upRoom(Room* upRoom){
    this->upRoom = upRoom;
}
void Room::set_downRoom(Room* downRoom){
    this->downRoom = downRoom;
}
void Room::set_leftRoom(Room* leftRoom){
    this->leftRoom = leftRoom;
}
void Room::set_rightRoom(Room* rightRoom){
    this->rightRoom = rightRoom;
}
void Room::set_isExit(bool isExit){
    this->isExit = isExit;
}
void Room::set_index(int index){
    this->index = index;
}
void Room::set_objects(vector<Object*> objects){
    this->objects = objects;
}
bool Room::get_isExit(){
    return this->isExit;
}
int Room::get_index(){
    return this->index;
}
vector <Object*> Room::get_objects(){
    return this->objects;
}
Room* Room::get_upRoom(){
    return this->upRoom;
}
Room* Room::get_downRoom(){
    return this->downRoom;
}
Room* Room::get_leftRoom(){
    return this->leftRoom;
}
Room* Room::get_rightRoom(){
    return this->rightRoom;
}
