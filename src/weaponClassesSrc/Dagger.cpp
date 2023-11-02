#include "../../header/weaponClassesHeader/Dagger.h"

Dagger::Dagger()
{
    this -> itemName = "Dagger";
    this -> itemCost = 0;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = 0;
    this -> weaponMovementBonus = 0;
    this -> weaponMovementSpeedModifier = daggerMovementSpeedModifier;
}

Dagger::Dagger(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = weaponTypeNumber;
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
    this -> weaponMovementSpeedModifier = daggerMovementSpeedModifier;
}

double Dagger::getWeaponMovementSpeedModifier()
{
    return daggerMovementSpeedModifier;
}

void Dagger::setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier)
{
    this -> weaponMovementSpeedModifier = daggerMovementSpeedModifier;
}