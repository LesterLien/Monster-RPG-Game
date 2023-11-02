#include "../header/Game.h"
#include "gtest/gtest.h"

// TESTING CONSTRUCTOR

// TESTING createPlayer() FUNCTION
TEST(gameTests, testCreatePlayerWithString) {
    Game *testGame = new Game();
    testGame->createPlayer("test");
    EXPECT_EQ(testGame->getPlayerName(), "test");
    EXPECT_EQ(testGame->getPlayer)
}

TEST(gameTests, testCreatePlayerWithChar) {
    Game *testGame = new Game();
    EXPECT_DEATH(testGame->createPlayer('t'), "Method does not take in char as a parameter");
}

TEST(gameTests, testCreatePlayerWithInt) {
    Game *testGame = new Game();
    EXPECT_DEATH(testGame->createPlayer(2), "Method does not take in int parameter");
}

// TESTING initializeTown() FUNCTION
TEST(gameTests, testInitializeTownWithString) {
    Game *testGame = new Game();
    testGame->initializeTown("Riverside");
    EXPECT_EQ(testGame->getTownName(), "Riverside");
}

TEST(gameTests, testInitializeTownWithChar) {
    Game *testGame = new Game();
    EXPECT_DEATH(testGame->initializeTown('t'), "Method does not take in char as a parameter.");
}

TEST(gameTests, testInitializeTownWithInt) {
    Game *testGame = new Game();
    EXPECT_DEATH(testGame->initializeTown(2), "Method does not take in int as a parameter.");
}

// TESTING visitNPC() FUNCTION
TEST(gameTests, testVisitNPCChemist) {
    Game *testGame = new Game();
    testGame->initializeTown("test");
    testGame->visitNPC(1); // 1 is option for Chemist
    EXPECT_EQ(testGame->getNPCName(), "Chemist");
}

TEST(gameTests, testVisitNPCWeaponsmith) {
    Game *testGame = new Game();
    testGame->initializeTown("test");
    testGame->visitNPC(2); // 2 is option for Weaponsmith
    EXPECT_EQ(testGame->getNPCName(), "Weaponsmith");
}

TEST(gameTests, testVisitNPCArmorsmith) {
    Game *testGame = new Game();
    testGame->initializeTown("test");
    testGame->visitNPC(3); // 3 is option for Armorsmith
    EXPECT_EQ(testGame->getNPCName(), "Armorsmith");
}

TEST(gameTests, testVisitNPCWithString) {
    Game *testGame = new Game(); 
    testGame->initializeTown("test");
    EXPECT_DEATH(testGame->visitNPC("Invalid"), "Method does not take in string as a paremeter");
}

TEST(gameTests, testVisitNPCWithChar) {
    Game *testGame = new Game(); 
    testGame->initializeTown("test");
    EXPECT_DEATH(testGame->visitNPC('t'), "Method does not take in char as a parameter.");
}

// TESTING playerSellsToNPC() FUNCTION

// TEST(gameTests)
// // TESTING playerBuysFromNPC() FUNCTION
// TEST(gameTests, testPlayerBuysFromNPC) {
//     Game *game = new Game();
//     game->initializeTown("test");
//     game->visitNPC(1);
//     game->playerBuysFromNPC(1);
//     EXPECT_EQ(game->getInventorySize(), 0);
// }

// TEST(gameTests, testPlayerBuysFromNPC) {
//     Game *game = new Game();
//     Item *sword = new Sword()
//     game->initializeTown("test");
//     game->visitNPC(1);
//     game->playerBuysFromNPC(1);
//     EXPECT_EQ(game->getInventorySize(), 0);
// }

// TESTING startBattle() FUNCTION
TEST(gameTests, testStartBattle) {
    Game *testGame = new Game(); 
    testGame->startBattle(); // enemy type is randomized
    EXPECT_TRUE(testGame->getBattleStatus());
}

TEST(gameTests, testStartBattleEnemy) {
    Game *testGame = new Game(); 
    testGame->startBattle(); // enemy type is randomized
    EXPECT_EQ(testGame->getEnemyName(), "Wandering Wolf"); // if enemy is type 0
    EXPECT_EQ(testGame->getEnemyName(), "Undead Knight"); // if enemy is type 1
    EXPECT_EQ(testGame->getEnemyName(), "Shrieker"); // if enemy is type 2
    EXPECT_EQ(testGame->getEnemyName(), "Minotaur"); // if enemy is type 3
}

// TESTING endBattle() FUNCTION
TEST(gameTests, testEndBattle) {
    Game *testGame = new Game(); 
    testGame->startBattle();
    testGame->endBattle();
    EXPECT_TRUE(!testGame->getBattleStatus());
}