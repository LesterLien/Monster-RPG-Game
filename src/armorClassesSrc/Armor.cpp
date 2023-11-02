#include "../../header/armorClassesHeader/Armor.h"

//Constructors
Armor::Armor()
{
    itemName = "Armor";
    itemCost = 0;
    itemType = armorTypeNumber;
    healthBonus = 0;
    healthModifier = 0;
}

Armor::Armor(string itemName, int itemCost, int healthBonus, double healthModifier)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = armorTypeNumber;
    this -> healthBonus = healthBonus;
    this -> healthModifier = healthModifier;
}

//Get Functions
int Armor::getArmorHealthBonus()
{
    return healthBonus;
}

double Armor::getArmorHealthModifier()
{
    return healthModifier;
}

//Modifiers
void Armor::setArmorHealthBonus(int healthBonus)
{
    this -> healthBonus = healthBonus;
}

void Armor::setArmorHealthModifier(double healthModifier)
{
    this -> healthModifier = healthModifier;
}