#ifndef TOWN_BASE_CLASS
#define TOWN_BASE_CLASS
#include <iostream>
#include <vector>
#include "../header/Npc.h"
#include "../header/Weaponsmith.h"
#include "../header/Chemist.h"
#include "../header/ArmorSmith.h"


using namespace std;

class Town {

    public: 

        //Constructors
        Town();
        Town(string townName);

        //Destructors
        ~Town();
        
        //Get Functions
        string getTownName();
        NPC* getTownMember(int index);

        //Scrapped
        // void printWelcomeMessage();
        // void printNPCList();
        // void printTownMenu();

    protected: 
        string townName = "";
        vector<NPC*> townPeople;
};

#endif