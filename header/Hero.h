#ifndef HERO_H
#define HERO_H

#include "../header/Character.h"
#include "../header/Item.h"
#include <string>
#include <cmath>

class Hero: public Character {
    public:
        //Constructors
        Hero();
        Hero(std::string);

        //Destructor
        ~Hero();

        //Accessors
        int getCurrentExp();
        int getGoldAmount();
        int getCurrentLevel();
        // std::string getRole();
        
        //Modifiers 
        void addGoldAmount(int);
        void addExperience(int);
        void addLevel();

    private:
        int currentExp = 0;
        int goldAmount = 0;
        int currentLevel = 0;
        // std::string role = "";
};

#endif