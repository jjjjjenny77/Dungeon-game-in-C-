#include "Monster.h"

Monster::Monster():GameCharacter(){

}

Monster::Monster(string name, int currentHealth, int attack, int defense):GameCharacter(name, "monster", currentHealth, attack, defense){
    set_name(name);
    set_currentHealth(currentHealth);
    set_attack(attack);
    set_defense(defense);
}

bool Monster::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    int answer;
    cout << "---------------------------------------------------------" << endl;
    cout << "Oh no! There is a monster!!!" << endl;
    cout << "Do you want to fight with "<<get_name()<<" (Health: " << get_currentHealth() << ", Attack: " << get_attack() << ", Defense: " << get_defense() << ")?"<<endl;
    cout << "1.yes! 2.escape to previous room 3.check my status" << endl;
    cin >> answer;
    if(answer==2){
        player->changeRoom(player->get_previousRoom());
    }
    else if(answer==1){
        while(get_currentHealth() > 0 && player->get_currentHealth() > 0){
            takeDamage(player->get_attack());
            player->takeDamage(get_attack());
        }
        if(get_currentHealth() > 0){
            cout << "You were beaten by " << get_name() << " QAQ" << endl;
            cout << "*************GAME OVER*************" << endl;
            exit(1);
            }
        else
            cout << "You beat " << get_name() << "!" << endl;
            return true;
    }
    else if(answer == 3){
        cout << object->get_name() << " ( Current health: " << get_currentHealth() << ", Attack: " << get_attack() << ", Defense: " << get_defense() << ")"<<endl;
        player->triggerEvent(player);
        cout << "----------------------------" << endl;
        cout << "Now, decided again:" << endl;
        cout<<"1.Fight! 2.Retreat"<<endl;
        cin>>answer;
        if(answer==2){
            player->changeRoom(player->get_previousRoom());
        }
        else if(answer==1){
            while(get_currentHealth()>0&&player->get_currentHealth()>0){
                takeDamage(player->get_attack());
                player->takeDamage(get_attack());
            }
            if(get_currentHealth()>0){
                cout<<"You were beaten by "<<get_name()<<endl;
                exit(1);
                }
            else
                cout<<"You beat "<<get_name()<<endl;
                return true;
        }

    }

}
