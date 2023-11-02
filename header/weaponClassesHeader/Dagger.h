#ifndef DAGGER_H
#define DAGGER_H

#include <iostream>
#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"

using std::string;

class Dagger : public Weapon {

public:
    const double daggerMovementSpeedModifier = 1.50;
    
    //Constructors
    Dagger();
    Dagger(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus);
    double getWeaponMovementSpeedModifier();
    void setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier);
};

#endif