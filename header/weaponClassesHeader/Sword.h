#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"

using std::string;

class Sword : public Weapon {

public:
    const double swordMovementSpeedModifier = 1.10;
    
    //Constructors
    Sword();
    Sword(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus);

    //Get Functions
    double getWeaponMovementSpeedModifier();

    //Modifiers
    void setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier);
};

#endif