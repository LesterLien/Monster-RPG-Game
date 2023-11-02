//libraries
#include <iostream>
#include <string>
#include "../header/Character.h"
#include "../header/GameController.h"

using namespace std;

//Constructor
GameController::GameController() {
    this->game = nullptr;
    this->isPlaying = true;
}

//Destructor
GameController::~GameController() {
    delete this->game;
}

/*  
name: startGame()
function: begins the game sequence by creating a hero
and displaying the main menu options.
*/
void GameController::startGame() {
    std::string playerName = "";

    clearTerminal();
    std::cout << "Your Adventure has Begun.\n\n"
              << "Press Enter to Continue\n";
    std::cin.ignore(1000, '\n');
    
    this->game = new Game();
    displayCharacterCreation();
    getline(cin, playerName);
    game->createPlayer(playerName);
    game -> setUpPlayer();
    clearTerminal();

    int choice = 0;
    displayMainMenu();
    std::cin >> choice;
    std::cout << std::endl;

    while (this->isPlaying) {

        if (choice == 1) {
            travelToTown();
        }
        else if (choice == 2) {
            enterBattle();
        }
        else if (choice == 3) {
            levelUpPlayer();
        }
        else if (choice == 4) {
            advancedDisplayInventoryPrompt();
        }
        else if (choice == 5)
        {
            equipItemPrompt();
        }
        else if (choice == 6)
        {
            lookAtCurrentStatsPrompt();
        }
        else if (choice == 7)
        {
            showPlayerHandPrompt();
        }
        else if (choice == 0) {
            exitGame();
        }
        else {
            std::cout << "Choose one of the options!\n";
        }

        if (isPlaying == 0)
        {
            clearTerminal();
            return;
        }

        game -> resetPlayer();
        displayMainMenu();
        std::cin >> choice;
        std::cout << std::endl;
    }
}

void GameController::travelToTown() {
    clearTerminal();
    
    int choice = -1;
    this->game->initializeTown("Riverside");
    
    displayTownMenu();
    std::cin >> choice;
    std::cout << std::endl;
    while (choice != 0) { 
        if (choice > 0 && choice < 4) {
            game->visitNPC(choice - 1); // chooses which type of NPC
            shopNPC();
        }
        else {
            std::cout << "Choose one of the options!\n";
        }
        displayTownMenu();
        std::cin >> choice;
        std::cout << std::endl;
    }
}

void GameController::shopNPC() {    //LOOOOK HEEEREEE
    int choice = -1;

    displayNPCMenu();
    std::cin >> choice;
    std::cout << std::endl;
    clearTerminal();
    while (choice != 0) 
    {
        if (choice == 1) // buy
        {  
            std::cout << "You have " << game -> getPlayerGold() << " gold!" << std::endl;
            
            game -> printNPCMenu();

            int buyChoice = -1;
            std::cin >> buyChoice;

            //Verify choice
            if (buyChoice > 0 && buyChoice <= game -> getNPCInventorySize())
            {
                game->playerBuysFromNPC(buyChoice - 1);

                std::cout << "You now have " << game -> getPlayerGold() << " gold!" << std::endl;
                std::cout << std::endl;

                std::cin.ignore(1000, '\n');
                std::cout << "Press Enter to Continue\n";
                std::cin.ignore(1000, '\n');
            }
        }
        else if (choice == 2) // sell
        { 
            displayInventory();
            std::cout << "You have " << game -> getPlayerGold() << " gold!" << std::endl;

            if (game -> getInventorySize() == 0)
            {
                std::cin.ignore(1000, '\n');
                std::cout << "Press Enter to Continue\n";
                std::cin.ignore(1000, '\n');
            }
            else
            {
                int sellChoice = -1;
                std::cin >> sellChoice;

                if (sellChoice > 0 && sellChoice <= game -> getInventorySize())
                {
                    game->playerSellsToNPC(sellChoice - 1);
                }

                std::cout << "You now have " << game -> getPlayerGold() << " gold!" << std::endl;
                std::cout << std::endl;

                std::cin.ignore(1000, '\n');
                std::cout << "Press Enter to Continue\n";
                std::cin.ignore(1000, '\n');
            }


        }
        else 
        {
            std::cout << "Choose one of the options!\n";
        }
        displayNPCMenu();
        std::cin >> choice;
        std::cout << std::endl;
        clearTerminal();
    }
}

/* name: displayExitMenu()
function: asks the user if they want to stop playing;
if the input is 0, quit the game.
*/
void GameController::exitGame() {
    clearTerminal();

    int choice = 0;
    displayExitMenu();
    std::cin.ignore(1000, '\n');
    std::cin >> choice;
    std::cin.ignore(1000, '\n');
     
    if (choice == 0) {
        this->isPlaying = false;
    }
}

void GameController::enterBattle() {
    clearTerminal();

    game->startBattle(); //ENEMY IS CREATED
    game -> setBattleStatus(1);

    while(game->getBattleStatus()) {
        int choice = -1;
        displayBattleMenu();
        std::cin >> choice;
        while (choice < 0 || choice > 3) {
            std::cout << "Choose one of the options!\n";
            displayBattleMenu();
            std::cin >> choice;
        }
        if (choice == 0) {
            game->playerFleesBattle();
        }
        else if (choice == 1) {
            game->playerAttacks();
        }
        else if (choice == 2) {
            game->playerBlocks();
        }
        else 
        {
            clearTerminal();
            equipItemPrompt();
        }

        //Enemy Attacks After Player Choice
        if (game -> getBattleStatus()) 
        {
            game-> enemyAttacks();
            game -> checkBattleStatus();
        }
        game -> setIsBlocked(0);

    }
    
    game->endBattle();
}

void GameController::selectInventoryIndex() {
    int choice = -1;

    std::cin >> choice;
    std::cout << std::endl;

    while(choice != 0) 
    {
        if (choice > 0 && choice <= game->getInventorySize())  //LLOOOOK HEREEE
        {  
            game->useItem(choice - 1);
        }
        else {
            std::cout << "Choose one of the options!\n";
            std::cin >> choice;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void GameController::levelUpPlayer() 
{
    clearTerminal();

    std::cout << "Note: Every time you level up, you gain 10 Max Health, 10 Attack Damage and 5 Movement Speed" << std::endl;
    std::cout << std::endl;

    std::cout << "Here are your old stats: " << std::endl;
    std::cout << std::endl;

    game -> getPlayerStats();

    if (game -> getPlayerExperience() >= 100) {
        game -> levelUpPlayer();
        
        std::cout << "You have leveled up!\n";
        std::cout << std::endl;

        std::cout << "Here are your new stats: " << std::endl;
        std::cout << std::endl;

        game -> getPlayerStats();
    }
    else {
        std::cout << "You do not have enough experience.\n";
        std::cout << std::endl;
    }

    std::cin.ignore(1000, '\n');
    std::cout << "Press Enter to Continue\n";
    std::cin.ignore(1000, '\n');
}
// Display Functions

/*  name: displayMainMenu()
function: ouputs main menu options
*/
void GameController::displayMainMenu() {
    clearTerminal();

    std::cout << "What would you like to do?\n"
              << "0: quit\n"
              << "1: travel to town\n"
              << "2: enter battle\n"
              << "3: level up\n"
              << "4: display inventory\n"
              << "5: equip an item\n"
              << "6: look at current stats\n"
              << "7: look at current gear\n\n"
              << "Choose an option: ";
}

void GameController::displayCharacterCreation() {
    clearTerminal();

    std::cout << ". . . . . Oh! I didn't see you there.\n"
              << "What was your name again?\n\n"
              << "Enter your name: ";
}

void GameController::displayTownMenu() {
    clearTerminal();

    std::cout << "Welcome to " << game->getTownName() << std::endl << std::endl
              << "What would you like to do?\n\n"
              << "0: leave\n"
              << "1: visit the chemist\n"
              << "2: visit the weaponsmith\n"
              << "3: visit the armorsmith\n\n"
              << "Choose an option: ";
}

void GameController::displayNPCMenu() {
    clearTerminal();
    std::cout << game->getNPCName() << "'s shop\n\n"
              << "0: leave\n"
              << "1: buy\n"
              << "2: sell\n"
              << "\nChoose an option: ";
}

void GameController::displayBattleMenu() {
    
    this->game->printBattleStatus();
    std::cout << "You are battling " << game->getEnemyName()
              << "\n\nWhat will you do?\n\n"
              << "0: flee\n"
              << "1: attack\n"
              << "2: block\n"
              << "3: use item\n\n"
              << "Choose an option: ";
}

void GameController::displayInventory() {
    clearTerminal();

    if (game -> getInventorySize() == 0)
    {
        std::cout << "You have nothing!" << std::endl; 
        std::cout << std::endl;
    }

    for (int i = 0; i < game->getInventorySize(); ++i) {
        std::cout << i + 1 << ": " << game->getItemName(i) << std::endl;
    }
    std::cout << std::endl;
    
}

void GameController::displayExitMenu() {
    clearTerminal(); 

    std::cout << "Do you want to stop playing?\n"
              << "0: yes\n"
              << "1: no\n\n"
              << "Choose an option: ";
}

void GameController::equipItemPrompt()
{
    clearTerminal();
    displayInventory();

    int equipChoice = 0;
    if (game -> getInventorySize() == 0)
    {
        std::cin.ignore(1000, '\n');
        std::cout << "Press Enter to Continue\n";
        std::cin.ignore(1000, '\n');
    }
    else
    {
        std::cout << "Choose one of the options! Type 0 to leave.\n";
        cin >> equipChoice;
    } 

    if (equipChoice > 0 && equipChoice <= (game -> getInventorySize()))
    {
        game->useItem(equipChoice - 1);
    }
    else
    {
        return;
    }

    game -> resetPlayer();
    std::cout << std::endl;
    std::cin.ignore(1000, '\n');
    std::cout << "Press Enter to Continue\n";
    std::cin.ignore(1000, '\n');
}

void GameController::showPlayerHandPrompt()
{
    clearTerminal();
    std::cout << "Current Weapon: " << game -> getPlayerCurrentHandName() << std::endl;
    std::cout << std::endl;

    std::cout << "Current Armor: " << game -> getPlayerCurrentArmorName() << std::endl;
    std::cout << std::endl;

    std::cin.ignore(1000, '\n');
    std::cout << "Press Enter to Continue\n";
    std::cin.ignore(1000, '\n');
}

void GameController::advancedDisplayInventoryPrompt()
{
    clearTerminal();
    displayInventory();

    std::cin.ignore(1000, '\n');
    std::cout << "Press Enter to Continue\n";
    std::cin.ignore(1000, '\n');
}

void GameController::lookAtCurrentStatsPrompt()
{
    clearTerminal();
    game -> getPlayerStats();
    std::cout << std::endl;

    std::cin.ignore(1000, '\n');
    std::cout << "Press Enter to Continue\n";
    std::cin.ignore(1000, '\n');
}

/*  name: clearTerminal()
function: clears the terminal
*/
void GameController::clearTerminal() {
    std::cout << std::string(100, '\n');
}

