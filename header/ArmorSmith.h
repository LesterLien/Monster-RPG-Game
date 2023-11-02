#ifndef NPC_ARMORSMITH_CLASS
#define NPC_ARMORSMITH_CLASS
#include <vector>

#include "../header/Npc.h"
#include "../header/Item.h"
#include "../header/armorClassesHeader/Armor.h"
#include "../header/armorClassesHeader/LightArmor.h"
#include "../header/armorClassesHeader/HeavyArmor.h"

#include <iostream>


class Armorsmith: public NPC
{
    public:
        //Constructors
        Armorsmith(string nonplayableName);
        ~Armorsmith();

        //print
        void npcMenu();

};
#endif