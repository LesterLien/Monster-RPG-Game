#include "../../header/weaponClassesHeader/Bow.h"

Bow::Bow()
{
    this -> itemName = "Bow";
    this -> itemCost = 0;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = 0;
    this -> weaponMovementBonus = 0;
    this -> weaponMovementSpeedModifier = bowMovementSpeedModifier;
}

Bow::Bow(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = weaponTypeNumber;    //CONST
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
    this -> weaponMovementSpeedModifier = bowMovementSpeedModifier; //CONST
}

void Bow::setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier)
{
    this -> weaponMovementSpeedModifier = bowMovementSpeedModifier;
}

double Bow::getWeaponMovementSpeedModifier()
{
    return bowMovementSpeedModifier;
}
