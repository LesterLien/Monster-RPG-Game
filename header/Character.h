#ifndef CHARACTER_H
#define CHARACTER_H

const int MAX_HEALTH = 100;

#include <string>
#include <iostream>

using std::cout;
using std::endl;

/*
The Character class is an abstract class that has common methods used
by the Hero and Enemy Classes
*/
class Character {
    public:
        // Constructors
        Character();
        Character(std::string &playerName);
        
        //Destructor
        ~Character();

        //Accessors
        std::string getName() const;
        int getHealth() const;
        int getMaxHealth() const;
        int getAttackDamage() const;
        int getCriticalAttackChance() const;
        int getMovementSpeed() const;

        //Modifiers
        void setName(std::string playerName);
        void setCurrentHealth(int);     //NEW : NAME MODIFIED
        void setMaxHealth(int);         //NEW
        void setAttackDamage(int);
        void setCriticalAttackChance(int);
        void setMovementSpeed(int);

        //print functions
        void printStats();

        private:
            std::string characterName = "";
            int currentHealth = MAX_HEALTH;
            int maxHealth = MAX_HEALTH;     //NEW
            int attackDamage = 0;
            int criticalAttackChance = 0;
            int movementSpeed = 0;
            
};

#endif