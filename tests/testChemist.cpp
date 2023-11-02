#include "gtest/gtest.h"
#include "../header/Chemist.h"
#include "gmock/gmock.h"



TEST(ChemistTests, testSellToPlayerPASS)
{
    Chemist *chemist = new Chemist("Bob");
    Item* item = new HealthPotion(25, 50);
    EXPECT_EQ((chemist->sellToPlayer(25, 0))->getItemName(), item->getItemName());
}

TEST(ChemistTests, testSellToPlayerFAIL)
{
    Chemist *chemist = new Chemist("Bob");
    Item* item = nullptr;
    EXPECT_EQ(chemist->sellToPlayer(10, 0), item);
}

TEST(ChemistTests, testBuyFromPlayerPASS)
{
    Chemist *chemist = new Chemist("Bob");
    Item* item = new HealthPotion(25, 50);
    EXPECT_EQ(chemist->buyFromPlayer(chemist->getItemAtIndex(0)), item->getItemCost());
}

TEST(ChemistTests, testGetNonplayableName)
{
    Chemist *chemist = new Chemist("Bob");
    EXPECT_EQ(chemist->getnonplayableName(), "Bob");
}