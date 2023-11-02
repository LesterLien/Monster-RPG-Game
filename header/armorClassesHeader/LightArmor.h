#ifndef LIGHTARMOR_H
#define LIGHTARMOR_H

#include "Armor.h"

class LightArmor : public Armor {

protected:
    const double lightArmorHealthModifier = 1.25; 

public:

    //Constructors
    LightArmor();
    LightArmor(string itemName, int itemCost, int healthBonus);

    //Get Functions
    double getArmorHealthModifier();

    //Modifiers
    void setArmorHealthModifier(double healthModifer);

};

#endif