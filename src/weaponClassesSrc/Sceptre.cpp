#include "../../header/weaponClassesHeader/Sceptre.h"

Sceptre::Sceptre()
{
    this -> itemName = "Sceptre";
    this -> itemCost = 0;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = 0;
    this -> weaponMovementBonus = 0;
    this -> weaponMovementSpeedModifier = sceptreMovementSpeedModifier;
}

Sceptre::Sceptre(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
    this -> weaponMovementSpeedModifier = sceptreMovementSpeedModifier;
}

double Sceptre::getWeaponMovementSpeedModifier()
{
    return sceptreMovementSpeedModifier;
}

void Sceptre::setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier)
{
    this -> weaponMovementSpeedModifier = sceptreMovementSpeedModifier;
}

