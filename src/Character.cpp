#include "../header/Character.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructors
Character::Character() {
    this->characterName = "";
    this->attackDamage = 10;
    this->movementSpeed = 10;
}

Character::Character(std::string &playerName) {
    this->characterName = playerName;
    this->attackDamage = 10;
    this->movementSpeed = 10;
}

//Destructor
Character::~Character() {}

// Accessors
std::string Character::getName() const {
    return this->characterName;
}

int Character::getHealth() const {
    return this->currentHealth;
}

int Character::getMaxHealth() const
{
    return this -> maxHealth;
}


int Character::getAttackDamage() const {
    return this->attackDamage;
}

int Character::getCriticalAttackChance() const {
    return this->criticalAttackChance;
}

int Character::getMovementSpeed() const {
    return this->movementSpeed;
}


// Modifiers
void Character::setName(std::string playerName) {
    this->characterName = playerName;
}

void Character::setCurrentHealth(int newHealth) {   //NEW : MODIFIED NAMING
    if (newHealth < 0) {
        this->currentHealth = 0;
    }
    else {
        this->currentHealth = newHealth;
    }
}

void Character::setMaxHealth(int newMaxHealth) //NEW
{
    this -> maxHealth = newMaxHealth;
}

void Character::setAttackDamage(int newAttackDamage) {
    this->attackDamage = newAttackDamage;
}
 
void Character::setCriticalAttackChance(int newCriticalAttackChance) {
    this->criticalAttackChance = newCriticalAttackChance;
}

void Character::setMovementSpeed(int newMovementSpeed) {
    this->movementSpeed = newMovementSpeed;
}

void Character::printStats() {

    cout << "Character Stats: " << endl;
    cout << "\tName: " << getName() << endl;
    cout << "\tHealth: " << getHealth() << "/" << getMaxHealth() << endl << endl;
    cout << "\tAttack Damage: " << getAttackDamage() << endl; 
    cout << "\tMovement Speed: " << getMovementSpeed() << endl; 
}
