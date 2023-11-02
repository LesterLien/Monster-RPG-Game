#ifndef WEAPON_H
#define WEAPON_H

//Libraries
#include <iostream>
#include "../../header/Item.h"

using std::string;

/*
Creates a weapon that allows the hero to deal bonus damage 
and have a movement speed bonus based on the weapon held.
*/

class Weapon : public Item {

protected: 
    int weaponDamageBonus = 0;
    int weaponMovementBonus = 0;

    double weaponMovementSpeedModifier = 0;
    
    const int weaponTypeNumber = 2;
public:

    //Constructors
    Weapon();
    Weapon(int weaponDamageBonus, int weaponMovementBonus);
    Weapon(string itemName, int weaponDamageBonus, int weaponMovementBonus);
    Weapon(string itemName, int itemCost,
    int weaponDamageBonus, int weaponMovementBonus, double weaponMovementSpeedModifier);

    //Destructors
    ~Weapon();

    //GetFunctions
    int getWeaponDamageBonus();
    int getWeaponMovementBonus();
    virtual double getWeaponMovementSpeedModifier();

    //Modifiers
    void setWeaponDamageBonus(int weaponDamageBonus);
    void setWeaponMovementBonus(int weaponMovementBonus);
    virtual void setWeaponMovementSpeedModifier(double weaponMovementSpeedModifier);

};

#endif