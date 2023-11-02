#include "../header/ArmorSmith.h"


Armorsmith::Armorsmith(string nonplayableName)
{
    this -> nonplayableName = nonplayableName;

    Armor* lightArmor1 = new LightArmor("Paper Armor", 25, 25); //string itemName, int itemCost, int healthBonus, double healthModifier
    Armor* lightArmor2 = new LightArmor("Ninja Suit", 55, 60);
    Armor* lightArmor3 = new LightArmor("Carbon Fiber", 100, 120);

    npcItems.push_back(lightArmor1);
    npcItems.push_back(lightArmor2);
    npcItems.push_back(lightArmor3);

    Armor* heavyArmor1 = new HeavyArmor("Knight Armor", 40, 70);
    Armor* heavyArmor2 = new HeavyArmor("Juggernaut Armor", 60, 100);
    Armor* heavyArmor3 = new HeavyArmor("Tachanka", 150, 200);

    npcItems.push_back(heavyArmor1);
    npcItems.push_back(heavyArmor2);
    npcItems.push_back(heavyArmor3);
}

Armorsmith::~Armorsmith()
{
    for (int i = 0; i < npcItems.size(); ++i)
    {
        delete npcItems.at(i);
    }

    npcItems.clear();
}

// void Armorsmith::printArmor()
// {
//     int listArmorNumber = 0;
//     for(int i = 0; i < armorItems.size()-1; ++i)
//     {
//         std::cout << listArmorNumber++ << ": ";
//         std::cout << armor << std::endl;
//     }
// }

// void Armorsmith::printArmorsmithMenu()
// {
//     std::cout << "Armor: " << std::endl;
//     std::cout << std::endl;
//     // printArmor();

//     std::cout << "Light Armor Variants (1.25 Max Health Multiplier):" << std::endl;
//     std::cout << "0: Paper Armor, 25 Gold, 25 Max Health Bonus" << std::endl;
//     std::cout << "1: Ninja Suit, 55 Gold, 60 Max Health Bonus" << std::endl;
//     std::cout << "2: Carbon Fiber, 100 Gold, 120 Max Health Bonus" << std::endl;
//     std::cout << std::endl;

//     std::cout << "Heavy Armor Variants (1.70 Max Health Multiplier):" << std::endl;
//     std::cout << "3: Knight Armor, 40 Gold, 70 Max Health Bonus" << std::endl;
//     std::cout << "4: Juggernaut Armor, 60 Gold, 100 Max Health Bonus" << std::endl;
//     std::cout << "5: Tachanka, 150 Gold, 200 Max Health Bonus" << std::endl;
//     std::cout << std::endl;
    
//     std::cout << "Which would you like to purchase? Type the corresponding item number to purchase." << std::endl;
// }

void Armorsmith::npcMenu()
{
    std::cout << "Armor: " << std::endl;
    std::cout << std::endl;
    
    std::cout << "Note: " << std::endl;
    std::cout << "Light Armor has a 1.25 Max Health Multiplier." << std::endl;
    std::cout << "Heavy Armor has a 1.70 Max Health Multiplier." << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < getInventorySize(); ++i)
    {
        if (i == 0)
        {
            std::cout << "Light Armor:" << std::endl;
        }
        else if (i == 3)
        {   
            std::cout << std::endl;
            std::cout << "Heavy Armor:" << std::endl;
        }

        std::cout << i + 1 << ": " << getItemAtIndex(i) -> getItemName() << ", " 
                  << getItemAtIndex(i) -> getItemCost() << " Gold, " 
                  << getItemAtIndex(i) -> getArmorHealthBonus() << " Max Health Bonus" << std::endl;

        // if (getItemAtIndex(i) -> getArmorHealthModifier() == 1.25)
        // {
        //     std::cout << "Light Armor" << std::endl;
        // }
        // else if (getItemAtIndex(i) -> getArmorHealthModifier() == 1.70)
        // {
        //     std::cout << "Heavy Armor" << std::endl;
        // }
    }
    std::cout << std::endl;

    std::cout << "To leave at any time, type 0 and hit enter." << std::endl;
    std::cout << std::endl;

    std::cout << "Which would you like to purchase? Type the corresponding item number to purchase." << std::endl;
}
