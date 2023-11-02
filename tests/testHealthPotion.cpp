#include "../header/HealthPotion.h"
#include "../header/Item.h"
#include "gtest/gtest.h"

//Classes
using ::Item;
using ::HealthPotion;

//Libraries
using std::cout;
using std::endl;
using std::string;

//CONSTRUCTOR TESTS
TEST(HealthPotionConstructor, testBasicHPConstructor)
{
    HealthPotion *healthPotion = new HealthPotion();
    EXPECT_EQ(healthPotion -> getHealingAmount(), 25);
}

TEST(HealthPotionConstructor, testParameterHPConstructorPostive)
{
    HealthPotion *healthPotion = new HealthPotion(10, 90);
    EXPECT_EQ(healthPotion -> getHealingAmount(), 90);
}

TEST(HealthPotionConstructor, testParameterHPConstructorNegative)
{
    HealthPotion *healthPotion = new HealthPotion(20, -40);
    EXPECT_EQ(healthPotion -> getHealingAmount(), 40);
}

TEST(HealthPotionConstructor, testParameterHPConstructorBasicName)
{
    HealthPotion *healthPotion = new HealthPotion();
    EXPECT_EQ(healthPotion -> getItemName(), "Health Potion");
}

TEST(HealthPotionConstructor, testParameterHPConstructorParameterDefaultName)
{
    HealthPotion *healthPotion = new HealthPotion();
    EXPECT_EQ(healthPotion -> getItemName(), "Health Potion");
}

TEST(HealthPotionConstructor, testParameterHPConstructorFull)   //NEW
{
    HealthPotion *healthPotion = new HealthPotion(20, 100);
    EXPECT_EQ(healthPotion -> getItemName(), "Health Potion");
    EXPECT_EQ(healthPotion -> getItemCost(), 20);
    EXPECT_EQ(healthPotion -> getItemType(), 1);
    EXPECT_EQ(healthPotion -> getHealingAmount(), 100);
}

//GET FUCNTION TESTS
TEST(HealthPotionConstructor, testGetHealingPositive)
{
    HealthPotion *healthPotion = new HealthPotion(30, 50);
    EXPECT_EQ(healthPotion -> getHealingAmount(), 50);
}

TEST(HealthPotionConstructor, testGetHealingNegative)
{
    HealthPotion *healthPotion = new HealthPotion(30, -50);
    EXPECT_EQ(healthPotion -> getHealingAmount(), 50);
}

//MODIFER FUNCTION TESTS
TEST(HealthPotionModifiers, testSetHealingPositive)
{
    HealthPotion *healthPotion = new HealthPotion();
    healthPotion -> setHealingAmount(70);

    EXPECT_EQ(healthPotion -> getHealingAmount(), 70);
}

TEST(HealthPotionModifiers, testSetHealingNegative)
{
    HealthPotion *healthPotion = new HealthPotion();
    healthPotion -> setHealingAmount(-40);

    EXPECT_EQ(healthPotion -> getHealingAmount(), 40);
}

//TEST DERIVED ITEM FUNCTIONS
TEST(HealthPotionName, testSetItemName)
{
    HealthPotion *healthPotion = new HealthPotion();
    healthPotion -> setItemName("HealthPotion");

    EXPECT_EQ(healthPotion -> getItemName(), "HealthPotion");
}

TEST(HealthPotionName, testSetItemCost) //NEW
{
    HealthPotion *healthPotion = new HealthPotion(40, 50);
    healthPotion -> setItemCost(12312);

    EXPECT_EQ(healthPotion -> getItemCost(), 12312);
}

TEST(HealthPotionName, testSetItemType) //NEW
{
    HealthPotion *healthPotion = new HealthPotion(40, 50);
    healthPotion -> setItemType(1234);

    EXPECT_EQ(healthPotion -> getItemType(), 1234);
}

TEST(HealthPotionName, testSetItemName2)
{
    HealthPotion *healthPotion = new HealthPotion();
    healthPotion -> setItemName("AmongUs");
    
    EXPECT_EQ(healthPotion -> getItemName(), "AmongUs");
}