#ifndef SCEPTRE_H
#define SCEPTRE_H

#include <iostream>
#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"

using std::string;

class Sceptre : public Weapon {

public:
    const double sceptreMovementSpeedModifier = 1.00;
    
    //Constructors
    Sceptre();
    Sceptre(string itemName, int itemCost, int weaponDamageBonus, int weaponMovementBonus);
    double getWeaponMovementSpeedModifier();
    void setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier);
};

#endif