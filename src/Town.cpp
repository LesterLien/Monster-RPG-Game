#include "../header/Town.h"

Town::Town() 
{
    townName = "";
}
Town::~Town() 
{
    for (int i = 0; i < townPeople.size(); ++i) {
        delete townPeople.at(i);
    }
    townPeople.clear();
}

Town::Town(string townName) 
{
    this->townName = townName;

    NPC* townMember1 = new Chemist("Chemist");

    NPC* townMember2 = new Weaponsmith("Weaponsmith");
    NPC* townMember3 = new Armorsmith("Armorsmith");

    this->townPeople.push_back(townMember1);
    this->townPeople.push_back(townMember2);
    this->townPeople.push_back(townMember3);
}

string Town::getTownName() 
{
    return townName;
}

NPC* Town::getTownMember(int index)
{
    return townPeople.at(index);
}