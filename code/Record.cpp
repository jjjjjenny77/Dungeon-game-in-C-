#include "Record.h"
Record::Record(){}
void Record::saveToFile(Player* player, vector<Room>& rooms)
{
    ofstream fplayer("recordplayer.txt");
    ofstream frooms("recordrooms.txt");
    Record::savePlayer(player, fplayer);
    Record::saveRooms(rooms, frooms);
}
void Record::loadFromFile(Player* player, vector<Room>& rooms)
{
    ifstream fplayer("recordplayer.txt");
    ifstream frooms("recordrooms.txt");
    string name,itemname;
    int currenthealth,attack,defense,index;
    fplayer >> name ;
    fplayer >> currenthealth ;
    fplayer >> attack ;
    fplayer >> defense ;
    fplayer >> index ;
    Record::loadRooms(rooms, frooms);
    player->set_name(name);
    player->set_currentHealth(currenthealth);
    player->set_attack(attack);
    player->set_defense(defense);
    player->set_currentRoom(&rooms[index]);
}

void Record::savePlayer(Player* player, ofstream& fplayer)
{
    fplayer << player->get_name() << endl;
    fplayer << player->get_currentHealth() << endl;
    fplayer << player->get_attack() << endl;
    fplayer << player->get_defense() << endl;
    fplayer << player->get_currentRoom()->get_index() << endl;
    if(!player->get_inventory().empty())
    {
        for(int i=0;i<player->get_inventory().size();i++)
        {
            fplayer << player->get_inventory()[i].get_name()<<endl;
        }
    }

}

void Record::saveRooms(vector<Room>& rooms, ofstream& frooms)
{
     Monster *monster1 = dynamic_cast<Monster*>(rooms[1].get_objects()[0]);
     Monster *monster5 = dynamic_cast<Monster*>(rooms[5].get_objects()[0]);
     frooms << monster1->get_currentHealth() << endl;
     frooms << monster5->get_currentHealth() << endl;
}

void Record::loadPlayer(Player* player, ifstream& fplayer)
{
    string name;
    int currenthealth,attack,defense,index;
    fplayer >> name ;
    fplayer >> currenthealth ;
    fplayer >> attack ;
    fplayer >> defense ;
    fplayer >> index ;
    player->set_name(name);
    player->set_currentHealth(currenthealth);
    player->set_attack(attack);
    player->set_defense(defense);

}
void Record::loadRooms(vector<Room>& rooms, ifstream& frooms)
{
    int monster1_currenthealth,monster5_currenthealth;
    frooms >> monster1_currenthealth ;
    frooms >> monster5_currenthealth ;
    Monster *monster1 = dynamic_cast<Monster*>(rooms[1].get_objects()[0]);
    Monster *monster5 = dynamic_cast<Monster*>(rooms[5].get_objects()[0]);
    monster1->set_currentHealth(monster1_currenthealth);
    monster5->set_currentHealth(monster5_currenthealth);
}
