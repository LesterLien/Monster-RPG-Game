#include "../header/Character.h"
#include "../header/Hero.h"
#include "../header/Enemy.h"
#include "../header/Town.h"

//NPC Classes
#include "../header/Npc.h"
#include "../header/ArmorSmith.h"
#include "../header/Chemist.h"
#include "../header/Weaponsmith.h"

//Item Classes
#include "../header/Item.h"

//Weapon Classes
#include "../header/weaponClassesHeader/Weapon.h"
#include "../header/weaponClassesHeader/Bow.h"
#include "../header/weaponClassesHeader/Dagger.h"
#include "../header/weaponClassesHeader/Sceptre.h"
#include "../header/weaponClassesHeader/Sword.h"

//Armor Classes
#include "../header/armorClassesHeader/Armor.h"
#include "../header/armorClassesHeader/HeavyArmor.h"
#include "../header/armorClassesHeader/LightArmor.h"

#include <vector>

#ifndef GAME_H
#define GAME_H

/*
The Game class is responsible for using the objects of hero, enemy, 
town, and NPC to execute the gameplay within anystate of the game. 
*/
class Game {
    public:
        //Constructor
        Game();

        //Destructor
        ~Game();
        
        //Accessors
        std::string getTownName() const;
        std::string getNPCName() const;
        std::string getPlayerName() const;
        int getPlayerGold() const;
        std::string getEnemyName() const;
        int getInventorySize() const;
        std::string getItemName(int) const;
        int getPlayerExperience() const;
        Item* getNPCItem(int) const;

        //Modifiers
        void createPlayer(std::string);
        void initializeTown(std::string);
        void visitNPC(int);
        void playerBuysFromNPC(int);
        void playerSellsToNPC(int);
        void startBattle();
        void endBattle();
        void levelUpPlayer();
        void appendItem(Item*);
        void useItem(int);
        // Modifiers (used in Battle)
        void playerFleesBattle();
        void playerAttacks();
        void playerBlocks() ;
        void enemyAttacks();

        // Display NPC Menus
        void printNPCMenu();
        void printBattleStatus();
        int getNPCInventorySize();

        //CONSTRUCTOR RELATED:
        void setUpPlayer();
        void resetPlayer();

        //Player Related
        void getPlayerStats();
        std::string getPlayerCurrentHandName();
        std::string getPlayerCurrentArmorName();

        //Enemy Related
        Enemy* getEnemy();
        void modifyEnemy(Enemy*);

        //I Borrowed This From GameController Functions
        void clearTerminal();
        void displayInventory();

        //Battle Status Related
        bool getBattleStatus() const;
        void setBattleStatus(int);

        void checkBattleStatus();

        //Block Status Related
        bool getIsBlocked() const;
        void setIsBlocked(int);


    private:
        // member variables
        Hero *player = nullptr;
        Enemy *enemy = nullptr;
        Town *currentTown = nullptr;
        NPC *currentNPC = nullptr;
        vector<Item *> inventory = {};

        
        Item* currentHand = nullptr;
        Item* currentArmor = nullptr;

        bool battleStatus = 0;
        bool isBlocked = 0;
        //helper functions
};



#endif