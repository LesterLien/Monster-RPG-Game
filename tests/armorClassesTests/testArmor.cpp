#include "../../header/Item.h"
#include "../../header/armorClassesHeader/Armor.h"
#include "gtest/gtest.h"

using ::Item;
using ::Armor;
using std::string;

//CONSTRUCTOR TESTS
TEST(ArmorConstructor, testArmorBasicContructor)
{
    Armor* armor = new Armor();

    EXPECT_EQ(armor -> getItemName(), "Armor");
    EXPECT_EQ(armor -> getItemCost(), 0);
    EXPECT_EQ(armor -> getItemType(), 3);
    EXPECT_EQ(armor -> getArmorHealthBonus(), 0);
    EXPECT_EQ(armor -> getArmorHealthModifier(), 0);
}

TEST(ArmorConstructor, testArmorFullConstructor)
{
    Armor* armor = new Armor("Plastic Armor", 10, 50, 1.20);

    EXPECT_EQ(armor -> getItemName(), "Plastic Armor");
    EXPECT_EQ(armor -> getItemCost(), 10);
    EXPECT_EQ(armor -> getItemType(), 3);
    EXPECT_EQ(armor -> getArmorHealthBonus(), 50);
    EXPECT_EQ(armor -> getArmorHealthModifier(), 1.20);
}

//GET FUNCTION TESTS
TEST(ArmorGetFunctions, testArmorGetItemNameSpaces)
{
    Armor* armor = new Armor("Wait A Second", 20, 50, 1.20);

    EXPECT_EQ(armor -> getItemName(), "Wait A Second");
}

TEST(ArmorGetFunctions, testArmorGetItemCost) //NEW
{
    Armor* armor = new Armor("Wait A Second", 20, 50, 1.20);

    EXPECT_EQ(armor -> getItemCost(), 20);
}

TEST(ArmorGetFunctions, testArmorGetItemType) //NEW
{
    Armor* armor = new Armor("Wait A Second", 20, 50, 1.20);

    EXPECT_EQ(armor -> getItemType(), 3);
}

TEST(ArmorGetFunctions, testArmorGetItemNameNumbers)
{
    Armor* armor = new Armor("1231", 10, 50, 1.20);

    EXPECT_EQ(armor -> getItemName(), "1231");
}

TEST(ArmorGetFunctions, testArmorGetItemNameSymbols)
{
    Armor* armor = new Armor("@!)#", 15, 40, 1.00);

    EXPECT_EQ(armor -> getItemName(), "@!)#");
}

TEST(ArmorGetFunctions, testArmorGetHealthBonus)
{
    Armor* armor = new Armor("Plated Chest", 50, 40, 1.00);

    EXPECT_EQ(armor -> getArmorHealthBonus(), 40);
}

TEST(ArmorGetFunctions, testArmorGetHealthModifier)
{
    Armor* armor = new Armor("Plated Chest", 60, 50, 1.40);

    EXPECT_EQ(armor -> getArmorHealthModifier(), 1.40);
}

//MODIFIER FUNCTION TESTS
TEST(ArmorModifiers, testArmorHealthBonus)
{
    Armor* armor = new Armor("Orange", 20, 50, 1.00);
    armor -> setArmorHealthBonus(100);

    EXPECT_EQ(armor -> getArmorHealthBonus(), 100);
}

TEST(ArmorModifiers, testArmorHealthModifier)
{
    Armor* armor = new Armor("Orange", 20, 50, 1.00);
    armor -> setArmorHealthModifier(1.20);

    EXPECT_EQ(armor -> getArmorHealthModifier(), 1.20);
}

//DERVIED MODIFER FUNCTION TESTS
TEST(ArmorDerivedModifiers, testArmorSetItemName)
{
    Armor* armor = new Armor("Orange", 20, 50, 1.00);
    armor -> setItemName("Rusty Armor");

    EXPECT_EQ(armor -> getItemName(), "Rusty Armor");
}

TEST(ArmorDerivedModifiers, testArmorSetItemCost)   //NEW
{
    Armor* armor = new Armor("Orange", 20, 50, 1.00);
    armor -> setItemCost(192391);

    EXPECT_EQ(armor -> getItemCost(), 192391);
}

TEST(ArmorDerivedModifiers, testArmorSetItemType)   //NEW
{
    Armor* armor = new Armor("Orange", 20, 50, 1.00);
    armor -> setItemType(194);

    EXPECT_EQ(armor -> getItemType(), 194);
}