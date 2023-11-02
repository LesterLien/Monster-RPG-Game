#ifndef NPC_WEAPONSMITH_CLASS
#define NPC_WEAPONSMITH_CLASS
#include <vector>

#include "../header/Npc.h"
#include "../header/Item.h"
#include "../header/weaponClassesHeader/Bow.h"
#include "../header/weaponClassesHeader/Dagger.h"
#include "../header/weaponClassesHeader/Sceptre.h"
#include "../header/weaponClassesHeader/Sword.h"
#include "../header/weaponClassesHeader/Weapon.h"

#include <iostream>
class Weaponsmith : public NPC
{
    public: 
    Weaponsmith(string nonplayableName);
    ~Weaponsmith();

    //print
    void npcMenu();
};
#endif
