#include "../../header/armorClassesHeader/LightArmor.h"

//Constructors
LightArmor::LightArmor()
{
    itemName = "Light Armor";
    itemCost = 0;
    itemType = armorTypeNumber;
    healthBonus = 0;
    healthModifier = lightArmorHealthModifier;
}

LightArmor::LightArmor(string itemName, int itemCost, int healthBonus)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = armorTypeNumber;
    this -> healthBonus = healthBonus;
    this -> healthModifier = lightArmorHealthModifier;
}

//Get Functions
double LightArmor::getArmorHealthModifier()
{
    return lightArmorHealthModifier;
}

//Modifiers
void LightArmor::setArmorHealthModifier(double healthModifer)
{
    this -> healthModifier = lightArmorHealthModifier;
}