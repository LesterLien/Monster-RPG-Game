#include "../header/Hero.h"
#include "../header/Character.h"
#include "../header/Item.h"

//Constructors
Hero::Hero() {
    this->currentExp = 0;
    this->goldAmount = 0;
    this->currentLevel = 0;
}

Hero::Hero(std::string playerName) {
    setName(playerName);
    this->currentExp = 0;
    this->goldAmount = 0;
    this->currentLevel = 0;
}

// Destructor
Hero::~Hero() {

}

// Accessors
int Hero::getCurrentExp() {
    return this->currentExp;
}

int Hero::getGoldAmount() {
    return this->goldAmount;
}

int Hero::getCurrentLevel() {
    return this->currentLevel;
}

//Modifiers
void Hero::addGoldAmount(int newGold) {
    this->goldAmount += newGold;
}

void Hero::addExperience(int newExp) {
    this->currentExp += newExp;
}

void Hero::addLevel() 
{
    this -> currentLevel = currentLevel + 1;

    setMaxHealth(getMaxHealth() + 10);
    setAttackDamage(getAttackDamage() + 10);
    setMovementSpeed(getMovementSpeed() + 5);
}

// Helper Functions