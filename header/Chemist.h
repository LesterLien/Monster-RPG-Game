#ifndef CHEMIST_H
#define CHEMIST_H

#include "Npc.h"
#include "../header/Item.h"
#include "../header/HealthPotion.h"

#include <iostream>
#include <vector>

using namespace std;

class Chemist : public NPC
{
    public: 
        //Constructors
        Chemist(string nonplayableName);
        ~Chemist();

        //print
        void npcMenu();


};

#endif