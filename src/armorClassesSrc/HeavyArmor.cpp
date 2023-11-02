#include "../../header/armorClassesHeader/HeavyArmor.h"

//Constructors
HeavyArmor::HeavyArmor()
{
    itemName = "Heavy Armor";
    itemCost = 0;
    itemType = armorTypeNumber;
    healthBonus = 0;
    healthModifier = heavyArmorHealthModifier;
}

HeavyArmor::HeavyArmor(string itemName, int itemCost, int healthBonus)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = armorTypeNumber;
    this -> healthBonus = healthBonus;
    this -> healthModifier = heavyArmorHealthModifier;
}

//Get Functions
double HeavyArmor::getArmorHealthModifier()
{
    return heavyArmorHealthModifier;
}

//Modifiers
void HeavyArmor::setArmorHealthModifier(double healthModifer)
{
    this -> healthModifier = heavyArmorHealthModifier;
}