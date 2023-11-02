#include "gtest/gtest.h"
#include "../header/Weaponsmith.h"
#include "gmock/gmock.h"
#include "../header/Npc.h"
#include "../header/Item.h"
#include "../header/weaponClassesHeader/Bow.h"
#include "../header/weaponClassesHeader/Dagger.h"
#include "../header/weaponClassesHeader/Sceptre.h"
#include "../header/weaponClassesHeader/Sword.h"
#include "../header/weaponClassesHeader/Weapon.h"
#include "gmock/gmock.h"
using::Weapon;
using::Bow;
using::Dagger;
using::Sceptre;
using::Sword;


TEST(WeaponsmithTests, testSellToPlayerPASS)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);
    EXPECT_EQ((weaponsmith->sellToPlayer(25, 0))->getItemName(), item->getItemName());
}

TEST(WeaponsmithTests, testSellToPlayerFAIL)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = nullptr;
    EXPECT_EQ(weaponsmith->sellToPlayer(10, 0), item);
}

TEST(WeaponsmithTests, testBuyFromPlayerPASS)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);
    EXPECT_EQ(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(0)), item->getItemCost());
}

TEST(WeaponsmithTests, testBuyFromPlayerFAIL)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);
    EXPECT_NE(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(1)), item->getItemCost());
}

TEST(WeaponsmithTests, testGetNonplayableName)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    EXPECT_EQ(weaponsmith->getnonplayableName(), "Bob");
}


//Test 2

TEST(WeaponsmithTests, testSellToPlayerPASS2)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Dagger("Slick Dagger", 25, 25,60);
    EXPECT_EQ((weaponsmith->sellToPlayer(25, 6))->getItemName(), item->getItemName());
}

TEST(WeaponsmithTests, testSellToPlayerFAIL2)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = nullptr;
    EXPECT_EQ(weaponsmith->sellToPlayer(10, 6), item);
}

TEST(WeaponsmithTests, testBuyFromPlayerPASS2)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Dagger("Slick Dagger", 25, 25,60);
    EXPECT_EQ(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(6)), item->getItemCost());
}

TEST(WeaponsmithTests, testBuyFromPlayerFAIL2)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Dagger("Slick Dagger", 25, 25,60);
    EXPECT_NE(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(5)), item->getItemCost());
}

TEST(WeaponsmithTests, testGetNonplayableName2)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Tree");
    EXPECT_EQ(weaponsmith->getnonplayableName(), "Tree");
}




TEST(WeaponsmithTests, testSellToPlayerPASSScep)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Sceptre("Traditional Staff", 40, 70,30);
    EXPECT_EQ((weaponsmith->sellToPlayer(40, 9))->getItemName(), item->getItemName());
}

TEST(WeaponsmithTests, testSellToPlayerFAILScep)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = nullptr;
    EXPECT_EQ(weaponsmith->sellToPlayer(10, 0), item);
}

TEST(WeaponsmithTests, testBuyFromPlayerPASSSCep)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Sceptre("Traditional Staff", 40, 70,30);
    EXPECT_EQ(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(9)), item->getItemCost());
}

TEST(WeaponsmithTests, testBuyFromPlayerFAILScep)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Sceptre("Traditional Staff", 40, 70,30);
    EXPECT_NE(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(10)), item->getItemCost());
}


//Test 4

TEST(WeaponsmithTests, testSellToPlayerPASS2Sword)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Sword("Longsword", 40, 70,30);
    EXPECT_EQ((weaponsmith->sellToPlayer(40, 3))->getItemName(), item->getItemName());
}

TEST(WeaponsmithTests, testSellToPlayerFAIL2Sword)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = nullptr;
    EXPECT_EQ(weaponsmith->sellToPlayer(10, 3), item);
}

TEST(WeaponsmithTests, testBuyFromPlayerPASS2Sword)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Sword("Longsword", 40, 70,30);
    EXPECT_EQ(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(3)), item->getItemCost());
}

TEST(WeaponsmithTests, testBuyFromPlayerFAIL2Sword)
{
    Weaponsmith *weaponsmith = new Weaponsmith("Bob");
    Item* item = new Sword("Longsword", 40, 70,30);
    EXPECT_NE(weaponsmith->buyFromPlayer(weaponsmith->getItemAtIndex(6)), item->getItemCost());
}
