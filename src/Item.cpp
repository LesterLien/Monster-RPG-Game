#include "../header/Item.h"

using std::cout;
using std::endl;
using std::string;

//Constructors
Item::Item() 
{
    itemName = "";
}

Item::Item(string itemName)
{
    this -> itemName = itemName;
}

Item::Item(string itemName, int itemCost, int itemType) //NEW
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = itemType;
}  

Item::~Item()
{}

//Get Functions
string Item::getItemName()
{
    return (itemName);
}

int Item::getItemCost()  //NEW
{ 
    return itemCost;
}

int Item::getItemType()   //NEW
{
    return itemType;
}

//Modifiers
void Item::setItemName(string itemName)
{
    this -> itemName = itemName;
}

void Item::setItemCost(int itemCost) //NEW
{
    this -> itemCost = itemCost;
}  

void Item::setItemType(int itemType) //NEW
{
    this -> itemType = itemType;
}  

//FOR INTERFACE PURPOSES
int Item::getWeaponDamageBonus()
{
    return 0;
}
int Item::getWeaponMovementBonus()
{
    return 0;
}

double Item::getWeaponMovementSpeedModifier()
{
    return 0;
}

int Item::getArmorHealthBonus()
{
    return 0;
}

double Item::getArmorHealthModifier()
{
    return 0;
}

int Item::getHealingAmount()
{
    return 0;
}
