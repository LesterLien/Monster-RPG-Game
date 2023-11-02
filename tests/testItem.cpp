#include "../header/Item.h"
#include "gtest/gtest.h"

using ::Item;

using std::cout;
using std::endl;
using std::string;

//CONSTRUCTOR TESTS

//TESTING BASIC CONSTRUCTOR
TEST(ItemTests, testItemBasicConstructor)
{
    Item *itemA = new Item();
    EXPECT_EQ(itemA -> getItemName(), "");
}

//TESTING PARAMETER CONSTRUCTOR WITH STRING
TEST(ItemTests, testItemParamterConstructorString)
{
    Item *itemA = new Item("Hand");

    EXPECT_EQ(itemA -> getItemName(), "Hand");
}

TEST(ItemTests, testItemFullConstructorString)
{
    Item *itemA = new Item("Hand", 25, 1);

    EXPECT_EQ(itemA -> getItemName(), "Hand");
    EXPECT_EQ(itemA -> getItemCost(), 25);
    EXPECT_EQ(itemA -> getItemType(), 1);
}

//TESTING PARAMETER CONSTRUCTOR WITH CHAR
// TEST(ItemTests, testItemParameterConstructorChar)
// {
//     char c = 'c';
//     EXPECT_DEATH(Item(c), "Item Constructor does not permit characters.");
// }

// //TESTING PARAMETER CONSTRUCTOR WITH INT
// TEST(ItemTests, testItemParameterConstructorInt)
// {
//     int four = 4;
//     EXPECT_DEATH(Item(four), "Item Constructor does not permit integers.");
// }

//Tests getItemName() if Item has a name
TEST(ItemTests, testItemGetItemName)
{
    Item *itemA = new Item("Apple", 10, 4);

    EXPECT_EQ(itemA -> getItemName(), "Apple");
}

TEST(ItemTests, testItemGetItemCost)
{
    Item *itemA = new Item("Apple", 10, 4);

    EXPECT_EQ(itemA -> getItemCost(), 10);
}

TEST(ItemTests, testItemGetItemType)
{
    Item *itemA = new Item("Apple", 10, 4);

    EXPECT_EQ(itemA -> getItemType(), 4);
}

//TEST MODIFIERS
TEST(ItemModifiers, testItemSetItemName)
{
    Item *itemA = new Item("Pear", 20, 5);
    itemA -> setItemName("Among Us");

    EXPECT_EQ(itemA -> getItemName(), "Among Us");
}

TEST(ItemModifiers, testItemSetItemCost)
{
    Item *itemA = new Item("Pear", 20, 5);
    itemA -> setItemCost(10);

    EXPECT_EQ(itemA -> getItemCost(), 10);
}

TEST(ItemModifiers, testItemSetItemType)
{
    Item *itemA = new Item("Pear", 20, 5);
    itemA -> setItemType(6);

    EXPECT_EQ(itemA -> getItemType(), 6);
}

//INTERFACE FUNCTIONS
TEST(ItemInterfaceFunctions, testItemWeaponDamageBonus)
{
    Item *itemA = new Item("Weapon", 20, 2);

    EXPECT_EQ(itemA -> getWeaponDamageBonus(), 0);
}

TEST(ItemInterfaceFunctions, testItemWeaponMovementBonus)
{
    Item *itemA = new Item("Weapon", 20, 2);

    EXPECT_EQ(itemA -> getWeaponMovementBonus(), 0);
}

TEST(ItemInterfaceFunctions, testItemWeaponMovementSpeedModifier)
{
    Item *itemA = new Item("Weapon", 20, 2);

    EXPECT_EQ(itemA -> getWeaponMovementSpeedModifier(), 0);
}

TEST(ItemInterfaceFunctions, testItemArmorHealthBonus)
{
    Item *itemA = new Item("Weapon", 20, 2);

    EXPECT_EQ(itemA -> getArmorHealthBonus(), 0);
}

TEST(ItemInterfaceFunctions, testItemArmorHealthModifier)
{
    Item *itemA = new Item("Weapon", 20, 2);

    EXPECT_EQ(itemA -> getArmorHealthModifier(), 0);
}

TEST(ItemInterfaceFunctions, testItemHealingAmount)
{
    Item *itemA = new Item("Weapon", 20, 2);

    EXPECT_EQ(itemA -> getHealingAmount(), 0);
}