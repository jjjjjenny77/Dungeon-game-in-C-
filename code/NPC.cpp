#include "NPC.h"

NPC::NPC():GameCharacter(){}

NPC::NPC(string name, string script, vector<Item> commodity):GameCharacter(name,"NPC",0,0,0){
    set_name(name);
    this->script = script;
    this->commodity = commodity;
}

bool NPC::triggerEvent(Object* object){
    int answer;
    Player* player = dynamic_cast<Player*>(object);
    cout << "-----------------------------------------" << endl;
    cout << "You found an old man standing over there." << endl;
    cout << ": Hello, " << object->get_name() << ". " << get_script();
    cout << " I have " << commodity[0].get_name() << "(" << commodity[0].get_health() << "," << commodity[0].get_attack() << "," << commodity[0].get_defense() << ")" << endl;
    cout << "1.yes 2.no" << endl;
    cin >> answer;
    if(answer == 1){
        player->addItem(commodity[0]);
        player->increaseStates(commodity[0].get_health(), commodity[0].get_attack(), commodity[0].get_defense());
        return true;
    }
    else if(answer==2){
        return false;
    }

}
void NPC::listCommodity(){
    for(int i = 0; i < commodity.size(); i++){
        cout<<commodity[i].get_name()<<endl;
    }
}
void NPC::set_script(string Script){
    this->script = script;
}
void NPC::set_commodity(vector<Item> commodity){
    this->commodity = commodity;
}
string NPC::get_script(){
    return this->script;
}
vector <Item> NPC::get_commodity(){
    return this->commodity;
}
