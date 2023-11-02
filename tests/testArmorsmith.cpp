#include "gtest/gtest.h"
#include "../header/ArmorSmith.h"
#include "../header/Npc.h"
#include "../header/Item.h"
#include "../header/armorClassesHeader/Armor.h"
#include "../header/armorClassesHeader/LightArmor.h"
#include "../header/armorClassesHeader/HeavyArmor.h"
#include "gmock/gmock.h"

using ::Armorsmith;
using ::LightArmor;
using ::HeavyArmor;
using ::Armor;


TEST(ArmorsmithTests, testSellToPlayerPASS)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = new LightArmor("Paper Armor", 25, 25);
    EXPECT_EQ((armorsmith->sellToPlayer(25, 0))->getItemName(), item->getItemName());
}

TEST(ArmorsmithTests, testSellToPlayerFAIL)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = nullptr;
    EXPECT_EQ(armorsmith->sellToPlayer(10, 0), item);
}

TEST(ArmorsmithTests, testBuyFromPlayerPASS)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = new LightArmor("Paper Armor", 25, 25);
    EXPECT_EQ(armorsmith->buyFromPlayer(armorsmith->getItemAtIndex(0)), item->getItemCost());
}

TEST(ArmorsmithTests, testBuyFromPlayerFAIL)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = new LightArmor("Paper Armor", 25, 25);
    EXPECT_NE(armorsmith->buyFromPlayer(armorsmith->getItemAtIndex(1)), item->getItemCost());
}

TEST(ArmorsmithTests, testGetNonplayableName)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    EXPECT_EQ(armorsmith->getnonplayableName(), "Bob");
}


//Test 2

TEST(ArmorsmithTests, testSellToPlayerPASS2)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = new HeavyArmor("Knight Armor", 40, 70);
    EXPECT_EQ((armorsmith->sellToPlayer(40, 3))->getItemName(), item->getItemName());
}

TEST(ArmorsmithTests, testSellToPlayerFAIL2)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = nullptr;
    EXPECT_EQ(armorsmith->sellToPlayer(30, 3), item);
}

TEST(ArmorsmithTests, testBuyFromPlayerPASS2)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = new HeavyArmor("Knight Armor", 40, 70);
    EXPECT_EQ(armorsmith->buyFromPlayer(armorsmith->getItemAtIndex(3)), item->getItemCost());
}

TEST(ArmorsmithTests, testBuyFromPlayerFAIL2)
{
    Armorsmith *armorsmith = new Armorsmith("Bob");
    Item* item = new HeavyArmor("Knight Armor", 40, 70);
    EXPECT_NE(armorsmith->buyFromPlayer(armorsmith->getItemAtIndex(5)), item->getItemCost());
}

TEST(ArmorsmithTests, testGetNonplayableName2)
{
    Armorsmith *armorsmith = new Armorsmith("Tree");
    EXPECT_EQ(armorsmith->getnonplayableName(), "Tree");
}