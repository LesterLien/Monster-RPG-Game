#ifndef BOW_H
#define BOW_H

#include <iostream>
#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"

using std::string;

class Bow : public Weapon {

public:
    const double bowMovementSpeedModifier = 1.25;

    //Constructors
    Bow();
    Bow(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus);
    double getWeaponMovementSpeedModifier();
    void setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier);
};

#endif