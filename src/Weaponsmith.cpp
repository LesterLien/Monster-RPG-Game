#include "../header/Weaponsmith.h"

Weaponsmith::Weaponsmith(string nonplayableName) {
    this -> nonplayableName = nonplayableName;

    Weapon* Bow1 = new Bow("Wooden Bow", 25, 25,50); //nt itemCost, int weaponDamageBonus, int weaponMovementBonus
    Weapon* Bow2 = new Bow("Sharpshooter", 55, 60,40);
    Weapon* Bow3 = new Bow("Quiet Killer", 100, 120,30);

    npcItems.push_back(Bow1);
    npcItems.push_back(Bow2);
    npcItems.push_back(Bow3);

    Weapon* Sword1 = new Sword("Longsword", 40, 70,30);
    Weapon* Sword2 = new Sword("Energized Blade", 60, 100,40);
    Weapon* Sword3 = new Sword("Maneater", 150, 200,50);

    npcItems.push_back(Sword1);
    npcItems.push_back(Sword2);
    npcItems.push_back(Sword3);

    Weapon* Dagger1 = new Dagger("Slick Dagger", 25, 25,60);
    Weapon* Dagger2 = new Dagger("Crimson Slayer", 55, 60,70);
    Weapon* Dagger3 = new Dagger("Quick Crimson", 100, 120,80);

    npcItems.push_back(Dagger1);
    npcItems.push_back(Dagger2);
    npcItems.push_back(Dagger3);

    Weapon* Sceptre1 = new Sceptre("Traditional Staff", 40, 70,30);
    Weapon* Sceptre2 = new Sceptre("Dark Reaper", 60, 100,30);
    Weapon* Sceptre3 = new Sceptre("Elsraniar", 150, 200,30);

    npcItems.push_back(Sceptre1);
    npcItems.push_back(Sceptre2);
    npcItems.push_back(Sceptre3);
}
Weaponsmith::~Weaponsmith()
{
    for (int i = 0; i < npcItems.size(); ++i)
    {
        delete npcItems[i];
    }

    npcItems.clear();
}
/*
string NpcWeaponsmith::getnonplayableName {
    return nonplayableName;
}

void NpcWeaponsmith::printweaponItems() {
    for(int i = 0; i < WeaponsmithItems.size()-1; i++) {
        cout << i << ". " << WeaponsmithItems[i] << endl;
    }
}
void NpcWeaponsmith::printWeaponsmithMenu() {
    cout << "weapons" << endl;
    printweaponItems();
    //cout << "If you wanna sell press some button";
}
Item& NpcWeaponsmith::sellToPlayer(int gold, int choice){
    Item* item = WeaponsmithItems[choice];
    if(gold >=  item.getCost()) {
        return item;
    }
    else {
        return nullptr;
    }
}
    
int NpcWeaponsmith::buyFromPlayer(Item* item) {
    if(item==nullptr) {
        return 0;
    }
    return item.getCost();
}*/

void Weaponsmith::npcMenu()
{
    std::cout << "Weapons: " << std::endl;
    std::cout << std::endl;

    std::cout << "Note: " << std::endl;
    std::cout << "Bow has a 1.25 Movement Speed Modifier." << std::endl;
    std::cout << "Dagger has a 1.50 Movement Speed Modifier." << std::endl;
    std::cout << "Sceptre has a 1.00 Movement Speed Modifier." << std::endl;
    std::cout << "Sword has a 1.10 Movement Speed Modifier." << std::endl;
    std::cout << std::endl;

    int i = 0;
    for (i = 0; i < getInventorySize(); ++i)
    {
        if (i == 0)
        {
            std::cout << "Bows:" << std::endl;
        }
        else if (i == 3)
        {   
            std::cout << std::endl;
            std::cout << "Sword:" << std::endl;
        }
        else if (i == 6)
        {
            std::cout << std:: endl;
            std::cout << "Dagger:" << std::endl;
        }
        else if (i == 9)
        {
            std::cout << std:: endl;
            std::cout << "Sceptre:" << std::endl;
        }

        std::cout << i + 1 << ": " << getItemAtIndex(i) -> getItemName() << ", " 
                  << getItemAtIndex(i) -> getItemCost() << " Gold, " 
                  << getItemAtIndex(i) -> getWeaponDamageBonus() << " Damage Bonus, " 
                  << getItemAtIndex(i) -> getWeaponMovementBonus() << " Movement Bonus" << std::endl;
        
        // if (getItemAtIndex(i) -> getWeaponMovementSpeedModifier() == 1.25)
        // {
        //     std::cout << "Bow" << std::endl;
        // }
        // else if (getItemAtIndex(i) -> getWeaponMovementSpeedModifier() == 1.50)
        // {
        //     std::cout << "Dagger" << std::endl;
        // }
        // else if (getItemAtIndex(i) -> getWeaponMovementSpeedModifier() == 1.00)
        // {
        //     std::cout << "Sceptre" << std::endl;
        // }
        // else if (getItemAtIndex(i) -> getWeaponMovementSpeedModifier() == 1.10)
        // {
        //     std::cout << "Sword" << std::endl;
        // }
    }
    std::cout << std::endl;

    std::cout << "To leave at any time, type 0 and hit enter." << std::endl;
    std::cout << std::endl;

    std::cout << "Which would you like to purchase? Type the corresponding item number to purchase." << std::endl;
}