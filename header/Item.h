#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using std::string;

class Item {

protected:
    string itemName = "";
    int itemCost = 0;
    int itemType = 0;

public: 
    
    //Constructors
    Item();
    Item(string itemName);
    Item(string itemName, int itemCost, int itemType);  //NEW

    //Destructors
    ~Item();

    //Get Functions
    string getItemName();
    int getItemCost();  //NEW
    int getItemType();  //NEW

    //Modifiers
    void setItemName(string itemName);
    void setItemCost(int itemCost);  //NEW
    void setItemType(int itemType);  //NEW

    // //Affect Player
    virtual int getWeaponDamageBonus();
    virtual int getWeaponMovementBonus();
    virtual double getWeaponMovementSpeedModifier();

    virtual int getArmorHealthBonus();
    virtual double getArmorHealthModifier();

    virtual int getHealingAmount();


    //Template Functions
    // virtual void useItem(int choice);

};

#endif