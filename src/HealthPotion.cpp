#include "../header/HealthPotion.h"
#include "../header/Item.h"

//Constructors
HealthPotion::HealthPotion()
{
    itemName = "Health Potion";
    this -> itemCost = 0;
    this -> itemType = potionTypeNumber;
    healingAmount = 25;
}

HealthPotion::HealthPotion(int itemCost, int healingAmount)
{
    itemName = "Health Potion";
    this -> itemCost = itemCost;
    this -> itemType = potionTypeNumber;
    this -> healingAmount = abs(healingAmount);
}

//Get Functions
int HealthPotion::getHealingAmount()
{
    return healingAmount;
}

//Modifiers
void HealthPotion::setHealingAmount(int healingAmount)
{
    this -> healingAmount = abs(healingAmount);
}