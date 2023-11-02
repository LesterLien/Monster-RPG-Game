#ifndef HEAVYARMOR_H
#define HEAVYARMOR_H

#include "Armor.h"

class HeavyArmor : public Armor {

protected:
    const double heavyArmorHealthModifier = 1.70; 

public:

    //Constructors
    HeavyArmor();
    HeavyArmor(string itemName, int itemCost, int healthBonus);

    //Get Functions
    double getArmorHealthModifier();

    //Modifiers
    void setArmorHealthModifier(double healthModifier);

};

#endif