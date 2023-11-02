#include "../../header/weaponClassesHeader/Weapon.h"
#include "../../header/Item.h"

//Constructors
Weapon::Weapon()
{
    itemName = "Default Weapon";
    weaponDamageBonus = 0;
    weaponMovementBonus = 0;
}

Weapon::Weapon(int weaponDamageBonus, int weaponMovementBonus)
{
    itemName = "Default Weapon";
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
}

Weapon::Weapon(string itemName, int weaponDamageBonus, int weaponMovementBonus)
{
    this -> itemName = itemName;
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
}

Weapon::Weapon(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus, double weaponMovementSpeedModifier)
{
    this -> itemName = itemName;
    this -> itemCost = itemCost;
    this -> itemType = weaponTypeNumber;    //Determined by class variable
    this -> weaponDamageBonus = weaponDamageBonus;
    this -> weaponMovementBonus = weaponMovementBonus;
    this -> weaponMovementSpeedModifier = weaponMovementSpeedModifier;
}

//Destructors
Weapon::~Weapon()
{

}

//GetFunctions
int Weapon::getWeaponDamageBonus()
{
    return weaponDamageBonus;
}

int Weapon::getWeaponMovementBonus()
{
    return weaponMovementBonus;
}

double Weapon::getWeaponMovementSpeedModifier()
{
    return weaponMovementSpeedModifier;
}

//Modifiers
void Weapon::setWeaponDamageBonus(int weaponDamageBonus)
{
    this -> weaponDamageBonus = weaponDamageBonus; 
}

void Weapon::setWeaponMovementBonus(int weaponMovementBonus)
{
    this -> weaponMovementBonus = weaponMovementBonus; 
}

void Weapon::setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier)
{
    this -> weaponMovementSpeedModifier = weaponMovementSpeedModifier;
}