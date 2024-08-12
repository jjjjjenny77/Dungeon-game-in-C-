#include "GameCharacter.h"

GameCharacter::GameCharacter():Object(){}
GameCharacter::GameCharacter(string name, string tag, int currentHealth, int attack, int defense):Object(name, "GameCharacter")
{
    set_tag(tag);
    set_name(name);
    this->currentHealth = currentHealth;
    this->attack = attack;
    this->defense = defense;
}
bool GameCharacter::checkisDead()
{
    if(currentHealth <= 0){return 1;}
    else{return 0;}
}
int GameCharacter::takeDamage(int damage)
{
    currentHealth = currentHealth - (damage - defense);
    return currentHealth;
}
void GameCharacter::set_maxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}
void GameCharacter::set_currentHealth(int currentHealth)
{
    this->currentHealth = currentHealth;
}
void GameCharacter::set_attack(int attack)
{
    this->attack = attack;
}
void GameCharacter::set_defense(int defense)
{
    this->defense = defense;
}
int GameCharacter::get_maxHealth()
{
    return this->maxHealth;
}
int GameCharacter::get_currentHealth()
{
    return this->currentHealth;
}
int GameCharacter::get_attack()
{
    return this->attack;
}
int GameCharacter::get_defense()
{
    return this->defense;
}
