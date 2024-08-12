#include "Dungeon.h"

Dungeon::Dungeon(){

}

void Dungeon::createPlayer(){
    string name;
    int choose;
    cout << "----------------------" << endl;
    cout << "Please enter your name" << endl;
    cin >> name;
    cout << "Choose your character: 1.Knight 2.Witch 3.Wsarrior "<<endl;
    cin>>choose;
    switch(choose){
        case 1:{
            Player player(name,75,75,20);
            player.set_maxHealth(500);
            this->player= player;
            break;
        }
        case 2:{
            Player player(name,100,50,10);
            player.set_maxHealth(500);
            this->player = player;
            break;
        }
        case 3:{
            Player player(name,150,25,15);
            player.set_maxHealth(500);
            this->player = player;
        }
    }
}

void Dungeon::createMap(){
    int room_num = 7;
    vector<Room> rooms;
    vector<Object*> object0, object1, object2, object3, object4, object5, object6;
    vector<Item> item1;
    for(int index = 0 ; index <= room_num ; index++){
        Room temp;
        temp.set_index(index);
        rooms.push_back(temp);
    }
    Monster* a = new Monster("fire dragon", 80, 20, 10);
    Monster* c = new Monster("BIG BOSS OOP", 500, 100, 10);
    Item* A = new Item("sword", 100, 25, 5);
    Item* B = new Item("book", 50, 30, 10);
    Item* C = new Item("medicine", 150, 15, 30);
    item1.push_back(*C);
    NPC *k = new NPC("trader","I've been stocked in here for a long time, now you are my only hope to escape.\nI wish you can beat all these monster!\nDo you want some supplies?",item1);

    object1.push_back(a);
    object2.push_back(k);
    object3.push_back(A);
    object4.push_back(B);
    object5.push_back(c);
    object6.push_back(nullptr);

    rooms[0] = Room(false,0,object0);
    rooms[1] = Room(false,1,object1);
    rooms[2] = Room(false,2,object2);
    rooms[3] = Room(false,3,object3);
    rooms[4] = Room(false,4,object4);
    rooms[5] = Room(false,5,object5);
    rooms[6] = Room(true,6,object6);

    rooms[0].set_upRoom(&rooms[1]);
    rooms[1].set_downRoom(&rooms[0]);
    rooms[1].set_upRoom(&rooms[2]);
    rooms[2].set_downRoom(&rooms[1]);
    rooms[1].set_leftRoom(&rooms[3]);
    rooms[3].set_rightRoom(&rooms[1]);
    rooms[1].set_rightRoom(&rooms[4]);
    rooms[4].set_leftRoom(&rooms[1]);
    rooms[4].set_upRoom(&rooms[5]);
    rooms[5].set_downRoom(&rooms[4]);
    rooms[5].set_rightRoom(&rooms[6]);
    rooms[6].set_leftRoom(&rooms[5]);
    this->rooms = rooms;
}
void Dungeon::handleMovement(){
    int choose;
    cout << "----------------------"<< endl;
    switch(player.get_currentRoom()->get_index()){
        case 0:
            cout << "choose your direction:" << endl;
            cout<<"1.go up 2.save game progress and logout"<<endl;
            cin>>choose;
            if (choose==1){
                player.set_currentRoom(&rooms[1]);
                player.set_previousRoom(&rooms[0]);
            }
            break;
        case 1:
            cout << "choose your direction:" << endl;
            cout<<"1.go up 2.go down 3.go right 4.go left 5.save game progress and logout"<<endl;
            cin>>choose;
            if(choose==1){
                player.set_currentRoom(&rooms[2]);
                player.set_previousRoom(&rooms[1]);
            }
            else if(choose==2){
                player.set_currentRoom(&rooms[0]);
                player.set_previousRoom(&rooms[1]);
            }
            else if(choose==3){
                player.set_currentRoom(&rooms[4]);
                player.set_previousRoom(&rooms[1]);
            }
            else if(choose==4){
                player.set_currentRoom(&rooms[3]);
                player.set_previousRoom(&rooms[1]);
            }
            else if(choose==5){
                Record record;
                record.saveToFile(&player,rooms);
                exit(1);
            }
            break;
        case 2:
            cout << "choose your direction:" << endl;
            cout<<"1.go down 2.save game progress and logout"<<endl;
            cin>>choose;
            if(choose==1){
                player.set_currentRoom(&rooms[1]);
                player.set_previousRoom(&rooms[2]);
            }
            else if(choose==2){
                Record record;
                record.saveToFile(&player,rooms);
                exit(1);
            }
            break;
        case 3:
            cout << "choose your direction:" << endl;
            cout<<"1.go right 2.save game progress and logout"<<endl;
            cin>>choose;
            if(choose==1){
                player.set_currentRoom(&rooms[1]);
                player.set_previousRoom(&rooms[3]);
            }
            else if(choose==2){
                Record record;
                record.saveToFile(&player,rooms);
                exit(1);
            }
            break;
        case 4:
            cout << "choose your direction:" << endl;
            cout<<"1.go left 2.go up 3.save game progress and logout"<<endl;
            cin>>choose;
            if(choose==1){
                player.set_currentRoom(&rooms[1]);
                player.set_previousRoom(&rooms[4]);
            }
            else if(choose==2){
                player.set_currentRoom(&rooms[5]);
                player.set_previousRoom(&rooms[4]);
            }
            else if(choose==3){
                Record record;
                record.saveToFile(&player,rooms);
                exit(1);
            }
            break;
        case 5:
            cout << "choose your direction:" << endl;
            cout<<"1.go right 2.go down 3.save game progress and logout"<<endl;
            cin>>choose;
            if(choose==1){
                player.set_currentRoom(&rooms[6]);
                player.set_previousRoom(&rooms[5]);
            }
            else if(choose==2){
                player.set_currentRoom(&rooms[4]);
                player.set_previousRoom(&rooms[5]);
            }
            else if(choose==3){
                Record record;
                record.saveToFile(&player,rooms);
                exit(1);
            }
            break;
        case 6:
            cout<<"CONGRATULATION  YOU  WIN !!!"<<endl;
            exit(1);

    }
}

void Dungeon::handleEvent(Object* b){
    Item* item = dynamic_cast<Item*>(b);
    Monster* monster = dynamic_cast<Monster*>(b);
    NPC* npc = dynamic_cast<NPC*>(b);
    if(item){
        item->triggerEvent(&player);
    }
    if(monster){
        if(monster->get_currentHealth()<=0){
            cout << "---------------------" << endl;
            cout << "The room is cleared !"<<endl;
            return handleMovement();
        }
        else
            monster->triggerEvent(&player);

    }
    if(npc){
        npc->triggerEvent(&player);
    }
    return handleMovement();

}


void Dungeon::chooseAction(vector<Object*> a){
    if(a.empty()){
        int choose;
        cout << "-------------------------------------------" << endl;
        cout << "Your in room 0 now, what do you want to do next?" << endl;
        cout << "1.Show my status" << " 2.move " << "3.save and logout" << endl;
        cin >> choose;
        switch (choose){
            case 1:
                player.triggerEvent(&player);
                break;
            case 2:
                handleMovement();
                break;
            case 3:
                Record record;
                    record.saveToFile(&player,rooms);
                    exit(1);
        }
        return;
    }

    else if(!a.empty()){
        handleEvent(a[0]);
        cout<<endl;
    }

}

void Dungeon::startGame(){

    int choose;
    cout<<"----------YOUR ADVENTURE START----------"<<endl;
    cout<<"1.Start a new game  2.load previous save"<<endl;
    cin>>choose;
    if(choose==1){
        createPlayer();
        createMap();
        player.set_currentRoom(&rooms[0]);
    }
    else if(choose==2){
        createMap();
        Record record;
        record.loadFromFile(&player,rooms);
    }
}
bool Dungeon::checkGameLogic(){
    if(player.get_currentHealth()<=0){
        return false;
    }
    else
        return true;
}
void Dungeon::runDungeon(){
    startGame();
    while(checkGameLogic()==true){
        chooseAction(player.get_currentRoom()->get_objects());
    }
}
