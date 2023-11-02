#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

//Inherited Class
#include "../header/Item.h"

//Libraries
#include <iostream>
#include <cmath>
using std::string;

/*
This class creates a health potion that holds healing amount.
When the player uses this item, the potion will heal the player for a set amount.
*/

class HealthPotion: public Item {

    private:
        int healingAmount = 0;

        const int potionTypeNumber = 1;

    public:

        //Constructors
        HealthPotion();
        HealthPotion(int itemCost, int healingAmount);

        //Get Functions
        int getHealingAmount();

        //Modifiers
        void setHealingAmount(int healingAmount);

};

#endif