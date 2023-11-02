#include <iostream>
#include "../header/Game.h"
#include "../header/Character.h"
#include "../header/Town.h"
#include "../header/Hero.h"


// Constructor
Game::Game() {
    this->player = nullptr;
    this->currentTown = nullptr;
    this->currentNPC = nullptr;
    this->enemy = nullptr;
    this->inventory = {};
}

void Game::setUpPlayer()
{
    Sword* weapon = new Sword("Hand", 20, 12, 10);
    LightArmor* armor = new LightArmor("Tshirt", 20, 10);

    appendItem(weapon);
    useItem(0);
    appendItem(armor);
    useItem(0);
    resetPlayer();

    weapon = nullptr;
    armor = nullptr;
}

void Game::resetPlayer()
{
    player -> setCurrentHealth(player -> getMaxHealth());
}

// Destructor
Game::~Game() {
    delete this->player;
    delete this->currentTown;
    if (this->currentHand != nullptr) {
        delete this->currentHand;
    }
    if (this->currentArmor != nullptr) {
        delete this->currentArmor;
    }
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory.at(i) != nullptr) {
            delete inventory.at(i);
        }
        inventory.at(i) = nullptr;
    }
    inventory.clear();
}

// Accessors
std::string Game::getTownName() const {
    return this->currentTown->getTownName();
}

std::string Game::getNPCName() const {
    return this->currentNPC->getnonplayableName();
}

std::string Game::getPlayerName() const {
    return this->player->getName();
}

int Game::getPlayerGold() const
{
    return (this -> player -> getGoldAmount());
}

std::string Game::getEnemyName() const {
    return this->enemy->getName();
}

int Game::getInventorySize() const {
    if (this->player == nullptr) {
        return 0;
    }
    return this->inventory.size();
}

bool Game::getBattleStatus() const {

    return battleStatus;
    
}

void Game::setBattleStatus(int battleStatus) 
{
    this -> battleStatus = battleStatus;
}

std::string Game::getItemName(int index) const {
    return this->inventory.at(index)->getItemName();
}

int Game::getPlayerExperience() const {
    return this->player->getCurrentExp();
}

Item * Game::getNPCItem(int index) const {
    return this->currentNPC->getItemAtIndex(index);
}

// Modifiers
void Game::createPlayer(std::string playerName) {
    this->player = new Hero(playerName);
}

void Game::initializeTown(std::string townName) {
    this->currentTown = new Town(townName);
}

void Game::visitNPC(int index) {
    currentNPC = currentTown->getTownMember(index);
}

void Game::playerSellsToNPC(int choice) 
{
    Item* item = this->inventory.at(choice);

    clearTerminal();
    this->player->addGoldAmount(item->getItemCost());
    inventory.erase(inventory.begin() + choice);
}

void Game::playerBuysFromNPC(int choice) {

    Item* item = this->currentNPC->sellToPlayer(this->player->getGoldAmount(), choice);

    if (item == nullptr)
    {
        clearTerminal();
        std::cout << "You couldn't afford this item!" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        appendItem(item);
        
        clearTerminal();
        std::cout << "You bought the item! Here is your updated inventory!" << std::endl;
        std::cout << std::endl;
        displayInventory();

        this->player->addGoldAmount(-(this->currentNPC->getItemAtIndex(choice)->getItemCost()));
    }
}

void Game::startBattle() {
    this->enemy = new Enemy(rand() % 4);
}

void Game::endBattle() {

    std::cin.ignore(1000, '\n');
    setBattleStatus(0);
    if (player->getHealth() <= 0) {
        std::cout << "You were defeated by " << enemy->getName() << ".\n"
                  << "Press enter to continue:\n";
        std::cin.ignore(1000, '\n');
    }
    else if (enemy -> getHealth() <= 0) {
        std::cout << "You recieved " << enemy->getExpReward() << " exp and "
                  << enemy->getGoldReward() << " gold.\n"
                  << "Press enter to continue:\n";
        std::cin.ignore(1000, '\n');
        enemy->rewardDeath(player);
    }
    else
    {
        std::cout << "You ran away from " << enemy->getName() << ". "
                  << "Press enter to continue:\n";
        std::cin.ignore(1000, '\n');
    }
    
    if(enemy != nullptr)
    {
        delete enemy;
        enemy = nullptr;
    }

    setIsBlocked(0);
    resetPlayer();
}

void Game::levelUpPlayer() 
{
    this-> player -> addLevel();
    this-> player -> addExperience(-100);
    resetPlayer(); //Just resets health
}

void Game::appendItem(Item* item)
{
    inventory.push_back(item);
}

void Game::useItem(int choice)
{
    Item * inventorySlot = inventory.at(choice);

    std::cout << std::endl;
    clearTerminal();

    if (inventorySlot -> getItemType() == 1)
    {
        if (player -> getHealth() == player -> getMaxHealth())
        {
            std::cout << "You're already full health!" << std::endl;
        }
        else
        {
            int updatedHealth = (player -> getHealth()) + (inventorySlot -> getHealingAmount());

            player -> setCurrentHealth(updatedHealth);
            inventory.erase(inventory.begin() + choice);

            std::cout << "Health Potion used!" << std::endl;
        }
    }
    else if (inventorySlot -> getItemType() == 2)
    {   
        //Removing Weapon From Hand, Removing Stats Given By Weapon
        if (currentHand != nullptr)
        {
            std::cout << "Removed " << currentHand -> getItemName() << "." << std::endl;

            int downgradeDamage = (player -> getAttackDamage()) - (currentHand -> getWeaponDamageBonus());
            int downgradeMovementSpeed = ((player -> getMovementSpeed())/(currentHand -> getWeaponMovementSpeedModifier())) - (currentHand -> getWeaponMovementBonus());

            player -> setAttackDamage(downgradeDamage);
            player -> setMovementSpeed(downgradeMovementSpeed);

            appendItem(currentHand);
            currentHand = nullptr;
        }

        //Updating Player With New Stats From New Weapon
        int updatedDamage = (player -> getAttackDamage()) + (inventorySlot -> getWeaponDamageBonus());
        int updatedMovementSpeed = ((player -> getMovementSpeed()) + (inventorySlot -> getWeaponMovementBonus())) * (inventorySlot -> getWeaponMovementSpeedModifier());

        player -> setAttackDamage(updatedDamage);
        player -> setMovementSpeed(updatedMovementSpeed);

        //Removing New Weapon From Inventory
        currentHand = inventorySlot;
        inventory.erase(inventory.begin() + choice);
        
        std::cout << "Equipping " << currentHand -> getItemName() << "." << std::endl;
        std::cout << "Attack damage and movement speed modified." << std::endl;
    }
    else if (inventorySlot -> getItemType() == 3)
    {
        //Removing Armor in CurrentArmor, Removing Stats Given By Armor
        if (currentArmor != nullptr)
        {
            cout << "Removed " << currentArmor -> getItemName() << "." << std::endl;

            int downgradeHealth = ((player -> getMaxHealth())/(currentArmor -> getArmorHealthModifier())) - (currentArmor -> getArmorHealthBonus());

            player -> setMaxHealth(downgradeHealth);

            appendItem(currentArmor);
            currentArmor = nullptr;
        }

        //Updating Player With New Stats From New Armor
        int updatedHealth = ((player -> getMaxHealth()) + (inventorySlot -> getArmorHealthBonus())) * (inventorySlot -> getArmorHealthModifier());

        player -> setMaxHealth(updatedHealth);

        //Removing New Armor From Inventory
        currentArmor = inventorySlot;
        inventory.erase(inventory.begin() + choice);

        std::cout << "Equipping " << currentArmor -> getItemName() << "." << std::endl;
        std::cout << "Max health modified." << std::endl;
    }
    else
    {
        std::cout << "Cannot equip that item." << std::endl;
    }
}

// BATTLE MENU FUNCTIONS
void Game::playerFleesBattle() {
    if (this->player->getMovementSpeed() >= this->enemy->getMovementSpeed()) {
        clearTerminal();
        std::cout << "GAME STATUS: You've fled." << std::endl;
        setBattleStatus(0);
        // endBattle();
    }
    else {
        clearTerminal();
        std::cout << "GAME STATUS: You are unable to flee.\n";
        std::cout << std::endl;
    }
}

void Game::playerAttacks() 
{
    clearTerminal();
    int totalDamage = player->getAttackDamage();
    int enemyHealth = enemy->getHealth();
    enemy->setCurrentHealth(enemyHealth - totalDamage);

    std::cout << "Game Status: " << std::endl;
    std::cout << std::endl;

    int attackMessageNum = rand() % 4;
    if (attackMessageNum == 0)
    {
        std::cout << player -> getName() << " took a bite out of " << enemy -> getName() << "'s arm." << std::endl;
    }
    else if (attackMessageNum == 1)
    {
        std::cout << player -> getName() << " hit " << enemy -> getName() << " with your best shot!" << std::endl;
    }
    else if (attackMessageNum == 2)
    {
        std::cout << player -> getName() << " headbutt " << enemy -> getName() << "." << std::endl;
    }
    else if (attackMessageNum == 3)
    {
        std::cout << player -> getName() << " attacked " << enemy -> getName() << "." << std::endl;
    }
    std::cout << player -> getName() << " did " << totalDamage << " damage to " << enemy -> getName() << "." << std::endl;
    std::cout << std::endl;
    checkBattleStatus();
}

void Game::playerBlocks() 
{
    std::cout << "Game Status: " << std::endl;
    std::cout << std::endl;

    int blockChance = rand() % 10;
    if (blockChance < 5) 
    {
        clearTerminal();

        enemy->changeBlockedStatus(); //Not needed anymore
        setIsBlocked(1);
        std::cout << std::endl;
            
        int counterAttackChance = rand() % 2;
        
        if (counterAttackChance == 0)
        {
            int totalDamage = player->getAttackDamage();
            int enemyHealth = enemy->getHealth();
            enemy->setCurrentHealth(enemyHealth - totalDamage);

            std::cout << "You blocked the attack and managed to counter attack!" << std::endl;
        }
        else
        {
            std::cout << "You blocked the attack!" << std::endl;
        }
        std::cout << std::endl;
        
    }
    else {
        clearTerminal();
        setIsBlocked(0);
        std::cout << "You could not block the attack.\n";
        std::cout << std::endl;
    }
}

void Game::enemyAttacks() 
{
    int totalDamage = 0;
    if (isBlocked == 0) 
    {
        totalDamage = enemy->getAttackDamage();
        checkBattleStatus();
    }
    else if (isBlocked == 1)
    {
        std::cout << enemy -> getName() << " was unable to attack." << std::endl;
        std::cout << std::endl;
        
        checkBattleStatus();
        return;
    }

    int playerHealth = player->getHealth();
    player->setCurrentHealth(playerHealth - totalDamage);

    int attackMessageNum = rand() % 7;
    if (attackMessageNum == 0)
    {
        std::cout << enemy-> getName() << " took a massive bite out of your arm." << std::endl;
    }
    else if (attackMessageNum == 1)
    {
        std::cout << enemy-> getName() << " hit your with their best shot!" << std::endl;
    }
    else if (attackMessageNum == 2)
    {
        std::cout << enemy-> getName() << " headbutt you." << std::endl;
    }
    else if (attackMessageNum == 3)
    {
        std::cout << enemy-> getName() << " slashed your leg." << std::endl;
    }
    else if (attackMessageNum == 4)
    {
        std::cout << enemy-> getName() << " hit their head on your head." << std::endl;
    }
    else if (attackMessageNum == 5)
    {
        std::cout << enemy-> getName() << " grabbed their telephone and threw it at you." << std::endl;
    }
    else if (attackMessageNum == 6)
    {
        std::cout << enemy-> getName() << " did a fortnite dance on you. You took emotional damage." << std::endl;
    }
    std::cout << player -> getName() << " took " << totalDamage << " damage from " << enemy -> getName() << "." << std::endl;
    std::cout << std::endl;

}

void Game::printNPCMenu() {
    currentNPC->npcMenu();
}

void Game::printBattleStatus() {
    player->printStats();
    std::cout << std::endl;

    enemy->printStats();
    std::cout << std::endl;
}

//NPC Related

int Game::getNPCInventorySize()
{
    return this -> currentNPC -> getInventorySize();
}

//Player Related
void Game::getPlayerStats()
{
    this -> player -> printStats();
    std::cout << std::endl;

    std::cout << "\tCurrent Level: " << this -> player -> getCurrentLevel() << std::endl;
    std::cout << "\tCurrent Experience: " << this -> player -> getCurrentExp() << "/100" << std::endl;
    std::cout << "\tGold: " << this -> player -> getGoldAmount() << std::endl;
}

std::string Game::getPlayerCurrentHandName()
{
    return this -> currentHand -> getItemName();
}

std::string Game::getPlayerCurrentArmorName()
{
    return this -> currentArmor -> getItemName();
}

//Enemy Related
Enemy* Game::getEnemy()
{
    return this -> enemy;
}

void Game::modifyEnemy(Enemy* enemy)
{
    this -> enemy = enemy;
}

void Game::checkBattleStatus()
{
    if(player -> getHealth() <= 0 || enemy -> getHealth() <= 0 || enemy == nullptr)
    {
        setBattleStatus(0);
    }
    else
    {
        setBattleStatus(1);
    }
}

//Block Status Related
bool Game::getIsBlocked() const
{
    return isBlocked;
}

void Game::setIsBlocked(int isBlocked)
{
    this -> isBlocked = isBlocked; 
}

//I Borrowed This From GameController Functions
void Game::clearTerminal()
{
    std::cout << std::string(100, '\n');
}

void Game::displayInventory()
{
    if (getInventorySize() == 0)
    {
        std::cout << "You have nothing!" << std::endl; 
        std::cout << std::endl;
    }

    for (int i = 0; i < getInventorySize(); ++i) {
        std::cout << i + 1 << ": " << getItemName(i) << std::endl;
    }
    std::cout << std::endl;
}