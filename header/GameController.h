#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>
#include "../header/Character.h"
#include "../header/Enemy.h"
#include "../header/Game.h"



/*
The GameController class is responsible for the logical flow of the RPG. It
initializes and outputs the various states of the game, including the 
character creation, main menu, town menu, level-up menu, and exit menu. It 
has the a private Game member variable variable which is the object that 
performs functions for the game to progress through a series of inputs 
by the player.
*/
class GameController {
    public:
    GameController();
    ~GameController();

    // Modifiers
    void startGame();
    void exitGame();
    void travelToTown();
    void shopNPC();
    void enterBattle();
    void levelUpPlayer();
    void selectInventoryIndex();
    void equipItemPrompt();
    void showPlayerHandPrompt();
    void lookAtCurrentStatsPrompt();
    void advancedDisplayInventoryPrompt();

    //display functions
    void displayMainMenu();
    void displayCharacterCreation();
    void displayTownMenu();
    void displayNPCMenu();
    void displayBattleMenu();
    void displayInventory();
    void displayQuestsMenu();
    void displayLevelUpMenu();
    void displayExitMenu();
    void clearTerminal();

    private:
    Game *game = nullptr;
    bool isPlaying = false;
};


#endif