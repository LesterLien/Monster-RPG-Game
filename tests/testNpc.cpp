#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/Npc.h"
#include "../header/Item.h"
#include "../header/weaponClassesHeader/Bow.h"
#include "../header/weaponClassesHeader/Weapon.h"
#include "gmock/gmock.h"
using::Weapon;
using::Bow;
#include <iostream>

using ::NPC;

TEST(NpcTests, testNonplayableName)
{
    NPC *npc = new NPC("Blacksmith");

    EXPECT_EQ(npc->getnonplayableName(), "Blacksmith");
}

TEST(NpcTests, testItemIndex)
{
    NPC *npc = new NPC("Blacksmith");
    Item* item = new Bow("Wooden Bow", 25, 25,50 );
    npc->appendNpcItems(item);
    EXPECT_EQ(npc->getItemAtIndex(0), item);
}
TEST(NpcTests, testInventorySize)
{
    NPC *npc = new NPC("Blacksmith");
    Item* item = new Bow("Wooden Bow", 25, 25,50 );
    npc->appendNpcItems(item);
    EXPECT_EQ(npc->getInventorySize(), 1);
}

TEST(NpcTests, testSellToPlayerPASS)
{
    NPC *npc = new NPC("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);
    npc->appendNpcItems(item);
    EXPECT_EQ((npc->sellToPlayer(25, 0))->getItemName(), item->getItemName());
}

TEST(NpcTests, testSellToPlayerFAIL)
{
    NPC *npc = new NPC("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);;
    Item* item2 = nullptr;
    npc->appendNpcItems(item);
    EXPECT_EQ(npc->sellToPlayer(10, 0), item2);
}

TEST(NpcTests, testBuyFromPlayerPASS)
{
    NPC *npc = new NPC("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);
    npc->appendNpcItems(item);
    EXPECT_EQ(npc->buyFromPlayer(npc->getItemAtIndex(0)), item->getItemCost());
}

TEST(NpcTests, testBuyFromPlayerFAIL)
{
    NPC *npc = new NPC("Bob");
    Item* item = new Bow("Wooden Bow", 25, 25,50);
    npc->appendNpcItems(item);
    Item* item2 = new Bow("BOWER", 50, 25,55);
    npc->appendNpcItems(item2);
    EXPECT_NE(npc->buyFromPlayer(npc->getItemAtIndex(1)), item->getItemCost());
}