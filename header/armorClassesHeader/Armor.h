#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include "../../header/Item.h"

class Armor : public Item {

protected:
    int healthBonus = 0;
    double healthModifier = 0;

    const int armorTypeNumber = 3;

public:
    //Constructors
    Armor();
    Armor(string itemName, int itemCost, int healthBonus, double healthModifier);

    //Get Functions
    int getArmorHealthBonus();
    virtual double getArmorHealthModifier();

    //Modifiers
    void setArmorHealthBonus(int healthBonus);
    virtual void setArmorHealthModifier(double healthModifier);

};

#endif