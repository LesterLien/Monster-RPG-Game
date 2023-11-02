#include "../../header/Item.h"
#include "../../header/armorClassesHeader/Armor.h"
#include "../../header/armorClassesHeader/HeavyArmor.h"
#include "gtest/gtest.h"

using ::Item;
using ::Armor;
using ::HeavyArmor;

using std::string;

//CONSTRUCTOR TESTS
TEST(HeavyArmorConstructor, testHeavyArmorBasicContructor)
{
    HeavyArmor* heavyArmor = new HeavyArmor();

    EXPECT_EQ(heavyArmor -> getItemName(), "Heavy Armor");
    EXPECT_EQ(heavyArmor -> getItemCost(), 0);
    EXPECT_EQ(heavyArmor -> getItemType(), 3);
    EXPECT_EQ(heavyArmor -> getArmorHealthBonus(), 0);
    EXPECT_EQ(heavyArmor -> getArmorHealthModifier(), 1.70);
}

TEST(HeavyArmorConstructor, testHeavyArmorFullContructor)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Knight Armor",70, 50);

    EXPECT_EQ(heavyArmor -> getItemName(), "Knight Armor");
    EXPECT_EQ(heavyArmor -> getItemCost(), 70);
    EXPECT_EQ(heavyArmor -> getItemType(), 3);
    EXPECT_EQ(heavyArmor -> getArmorHealthBonus(), 50);
    EXPECT_EQ(heavyArmor -> getArmorHealthModifier(), 1.70);
}

//DERIVED GET FUNCTIONS : ARMOR AND ITEM

TEST(HeavyArmorGetFunctions, testHeavyArmorGetItemName)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Juggernaut", 200, 150);

    EXPECT_EQ(heavyArmor -> getItemName(), "Juggernaut");
}

TEST(HeavyArmorGetFunctions, testHeavyArmorGetItemCost) //NEW
{
    HeavyArmor* heavyArmor = new HeavyArmor("Juggernaut", 200, 150);

    EXPECT_EQ(heavyArmor -> getItemCost(), 200);
}

TEST(HeavyArmorGetFunctions, testHeavyArmorGetItemType) //NEW
{
    HeavyArmor* heavyArmor = new HeavyArmor("Juggernaut", 200, 150);

    EXPECT_EQ(heavyArmor -> getItemType(), 3);
}

TEST(HeavyArmorGetFunctions, testHeavyArmorGetHealthBonus)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Juggernaut", 200, 150);

    EXPECT_EQ(heavyArmor -> getArmorHealthBonus(), 150);
}

TEST(HeavyArmorGetFunctions, testHeavyArmorGetHealthModifier)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Tachanka", 400, 300);

    EXPECT_EQ(heavyArmor -> getArmorHealthModifier(), 1.70);
}


//DERIVED MODIFER FUNCTIONS : ARMOR AND ITEM

TEST(HeavyArmorModifiers, testHeavyArmorItemNameModifier)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Tachanka", 400, 300);

    heavyArmor -> setItemName("I CANT MOVE");
    EXPECT_EQ(heavyArmor -> getItemName(), "I CANT MOVE");
}

TEST(HeavyArmorModifiers, testHeavyArmorItemCostModifier)   //NEW
{
    HeavyArmor* heavyArmor = new HeavyArmor("Tachanka", 400, 300);

    heavyArmor -> setItemCost(923193);
    EXPECT_EQ(heavyArmor -> getItemCost(), 923193);
}

TEST(HeavyArmorModifiers, testHeavyArmorItemTypeModifier)   //NEW
{
    HeavyArmor* heavyArmor = new HeavyArmor("Tachanka", 400, 300);

    heavyArmor -> setItemType(1235);
    EXPECT_EQ(heavyArmor -> getItemType(), 1235);
}

TEST(HeavyArmorModifiers, testHeavyArmorHealthBonus)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Ancient Vile", 700, 500);

    heavyArmor -> setArmorHealthBonus(1000);
    EXPECT_EQ(heavyArmor -> getArmorHealthBonus(), 1000);
}

TEST(HeavyArmorModifiers, testHeavyArmorHealthModifier)
{
    HeavyArmor* heavyArmor = new HeavyArmor("Ancient Vile", 700, 500);

    heavyArmor -> setArmorHealthModifier(1.20);
    EXPECT_NE(heavyArmor -> getArmorHealthModifier(), 1.20);
    EXPECT_EQ(heavyArmor -> getArmorHealthModifier(), 1.70);
}
