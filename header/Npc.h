#ifndef NPC_BASE_CLASS
#define NPC_BASE_CLASS
#include <string>
#include "../header/Item.h"
#include <iostream>
#include <vector>

using namespace std;

class NPC
{
protected:
    std::string nonplayableName = "";
    std::vector<Item *> npcItems;

public:
    NPC();
    ~NPC();
    NPC(std::string nonplayableName);
    std::string getnonplayableName();
    
    Item* sellToPlayer(int gold, int choice);                  //possibly returns int for gold and takes in item to be sold
    int buyFromPlayer(Item *item);     //returns an item and takes in gold and number

    Item* getItemAtIndex(int position);
    int getInventorySize();
    void appendNpcItems(Item* item);

    virtual void npcMenu();
};


#endif