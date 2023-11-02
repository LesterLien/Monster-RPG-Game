#include "../../header/Item.h"
#include "../../header/armorClassesHeader/Armor.h"
#include "../../header/armorClassesHeader/LightArmor.h"
#include "gtest/gtest.h"

using ::Item;
using ::Armor;
using ::LightArmor;

using std::string;

//CONSTRUCTOR TESTS
TEST(LightArmorConstructor, testLightArmorBasicContructor)
{
    LightArmor* lightArmor = new LightArmor();

    EXPECT_EQ(lightArmor -> getItemName(), "Light Armor");
    EXPECT_EQ(lightArmor -> getItemCost(), 0);
    EXPECT_EQ(lightArmor -> getItemType(), 3);
    EXPECT_EQ(lightArmor -> getArmorHealthBonus(), 0);
    EXPECT_EQ(lightArmor -> getArmorHealthModifier(), 1.25);
}

TEST(LightArmorConstructor, testLightArmorFullContructor)
{
    LightArmor* lightArmor = new LightArmor("Paper Armor", 5, 10);

    EXPECT_EQ(lightArmor -> getItemName(), "Paper Armor");
    EXPECT_EQ(lightArmor -> getItemCost(), 5);
    EXPECT_EQ(lightArmor -> getItemType(), 3);
    EXPECT_EQ(lightArmor -> getArmorHealthBonus(), 10);
    EXPECT_EQ(lightArmor -> getArmorHealthModifier(), 1.25);
}

//DERIVED GET FUNCTIONS : ARMOR AND ITEM

TEST(LightArmorGetFunctions, testLightArmorGetItemName)
{
    LightArmor* lightArmor = new LightArmor("Ninja Suit", 15, 20);

    EXPECT_EQ(lightArmor -> getItemName(), "Ninja Suit");
}

TEST(LightArmorGetFunctions, testLightArmorGetItemCost) //NEW
{
    LightArmor* lightArmor = new LightArmor("Ninja Suit", 15, 20);

    EXPECT_EQ(lightArmor -> getItemCost(), 15);
}

TEST(LightArmorGetFunctions, testLightArmorGetItemType) //NEW
{
    LightArmor* lightArmor = new LightArmor("Ninja Suit", 15, 20);

    EXPECT_EQ(lightArmor -> getItemType(), 3);
}

TEST(LightArmorGetFunctions, testLightArmorGetHealthBonus)
{
    LightArmor* lightArmor = new LightArmor("Ninja Suit", 15, 20);

    EXPECT_EQ(lightArmor -> getArmorHealthBonus(), 20);
}

TEST(LightArmorGetFunctions, testLightArmorGetHealthModifier)
{
    LightArmor* lightArmor = new LightArmor("Carbon Fiber Suit", 30, 50);

    EXPECT_EQ(lightArmor -> getArmorHealthModifier(), 1.25);
}


//DERIVED MODIFER FUNCTIONS : ARMOR AND ITEM

TEST(LightArmorModifiers, testLightArmorItemNameModifier)
{
    LightArmor* lightArmor = new LightArmor("Carbon Fiber Suit", 30, 50);

    lightArmor -> setItemName("Snake???");
    EXPECT_EQ(lightArmor -> getItemName(), "Snake???");
}

TEST(LightArmorModifiers, testLightArmorItemCostModifier)   //NEW
{
    LightArmor* lightArmor = new LightArmor("Carbon Fiber Suit", 30, 50);

    lightArmor -> setItemCost(123081);
    EXPECT_EQ(lightArmor -> getItemCost(), 123081);
}

TEST(LightArmorModifiers, testLightArmorItemTypeModifier)   //NEW
{
    LightArmor* lightArmor = new LightArmor("Carbon Fiber Suit", 30, 50);

    lightArmor -> setItemType(1129);
    EXPECT_EQ(lightArmor -> getItemType(), 1129);
}

TEST(LightArmorModifiers, testLightArmorHealthBonus)
{
    LightArmor* lightArmor = new LightArmor("Sneaking Suit", 70, 80);

    lightArmor -> setArmorHealthBonus(132);
    EXPECT_EQ(lightArmor -> getArmorHealthBonus(), 132);
}

TEST(LightArmorModifiers, testLightArmorHealthModifier)
{
    LightArmor* lightArmor = new LightArmor("Sneaking Suit", 70, 80);

    lightArmor -> setArmorHealthModifier(9.00);
    EXPECT_NE(lightArmor -> getArmorHealthModifier(), 9.00);
    EXPECT_EQ(lightArmor -> getArmorHealthModifier(), 1.25);
}
