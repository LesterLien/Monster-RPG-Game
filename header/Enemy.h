#ifndef ENEMY_H
#define ENEMY_H


#include <string>
#include <iostream>
#include "../header/Hero.h"
#include "../header/Character.h"

using std::cout;
using std::endl;
using std::string; 

class Enemy : public Character {

    public: 
        //constructors
        Enemy();
        Enemy(int);
        //Destructor
        ~Enemy();

        //Accessors
        int getEnemyDamage();
        string getEnemyStatement();
        int getGoldReward();
        int getExpReward();
        int getItemReward();
        bool attackBlocked();


        //Modifiers
        void rewardDeath(Hero *); 
        void changeBlockedStatus();
        


        //print functions
        void printEnemyDeathStatement();

        //void rewardDeath(Hero *x); 

    private: 
        bool attackIsBlocked = false;
        int enemyDamage = 0; 
        int goldReward = 10; 
        int expReward = 10;
};

#endif
