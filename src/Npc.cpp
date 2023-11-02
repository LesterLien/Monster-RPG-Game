#include "../header/Npc.h"


NPC::NPC()
{
    this->nonplayableName = "";
}


NPC::NPC(std::string nonplayableName)
{
    this->nonplayableName = nonplayableName;
}

std::string NPC::getnonplayableName()
{
    return this->nonplayableName;
}

Item* NPC::getItemAtIndex(int position)
{
    return(npcItems.at(position));
}

int NPC::getInventorySize()
{
    return(npcItems.size());
}

NPC::~NPC()
{
    for (int i = 0; i < npcItems.size(); ++i)
    {
        delete npcItems.at(i);
    }

    npcItems.clear();
}


Item* NPC::sellToPlayer(int gold, int choice)
{
    Item* item = npcItems.at(choice);

    if (gold >=  item -> getItemCost()) 
    {
        return item;
    }
    else 
    {
        return nullptr;
    }
}
    
int NPC::buyFromPlayer(Item* item) 
{
    if(item==nullptr) 
    {
        return 0;
    }
    return item -> getItemCost();
}
void NPC::appendNpcItems(Item* item)
{
    npcItems.push_back(item);
}

void NPC::npcMenu()
{
    cout << "Blank NPC Menu" << endl;
    //THIS VER SHOULD NOT RUN
}