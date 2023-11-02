#include "../header/Chemist.h"

Chemist::Chemist(string nonplayableName) 
{
    this->nonplayableName = nonplayableName;

    HealthPotion* healthPotion1 = new HealthPotion(25, 50);

    npcItems.push_back(healthPotion1);   
}

Chemist::~Chemist()
{
    for (int i = 0; i < npcItems.size(); ++i)
    {
        delete npcItems.at(i);
    }

    npcItems.clear();
}
// void Chemist::printPotionItems() 
// {
//     for(int i = 0; i < chemistItems.size()-1; i++) 
//     {
//         cout << i << ". " << chemistItems[i] << endl;
//     }
// }

// void Chemist::printChemistMenu() 
// {
//     std::cout << "Potions: " << std::endl;
//     std::cout << std::endl;
//     // printPotionItems();
//     //cout << "If you wanna sell press some button";

//     std::cout << "Health Potion Variants:" << std::endl;
//     std::cout << "0: Standard, 25 Gold, 50 Health Healing" << std::endl;

//     std::cout << "Which would you like to purchase? Type the corresponding item number to purchase." << std::endl;
// }

void Chemist::npcMenu()
{
    std::cout << "Potions: " << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < getInventorySize(); ++i)
    {
        std::cout << i + 1 << ": " << getItemAtIndex(i) -> getItemName() << ", " 
                  << getItemAtIndex(i) -> getItemCost() << " Gold, " 
                  << getItemAtIndex(i) -> getHealingAmount() << " Healing Amount";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "To leave at any time, type 0 and hit enter." << std::endl;
    std::cout << std::endl;

    std::cout << "Which would you like to purchase? Type the corresponding item number to purchase." << std::endl;
}