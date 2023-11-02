#include "../../header/weaponClassesHeader/Sword.h"

Sword::Sword()
{
    this -> itemName = "Sword";
    this -> itemCost = 0;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = 0;
    this -> weaponMovementBonus = 0;
    this -> weaponMovementSpeedModifier = swordMovementSpeedModifier;
}

Sword::Sword(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
    this -> weaponMovementSpeedModifier = swordMovementSpeedModifier;
}

double Sword::getWeaponMovementSpeedModifier()
{
    return swordMovementSpeedModifier;
}

void Sword::setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier)
{
    this -> weaponMovementSpeedModifier = swordMovementSpeedModifier;
}