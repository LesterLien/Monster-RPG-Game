#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"
#include "../../header/weaponClassesHeader/Sword.h"
#include "gtest/gtest.h"

using ::Item;
using ::Weapon;
using ::Sword;

using std::string;

//CONSTRUCTOR TESTS
TEST(SwordConstructor, testSwordBasicConstructor)
{
    Sword* sword = new Sword();

    EXPECT_EQ(sword -> getItemName(), "Sword");
    EXPECT_EQ(sword -> getItemCost(), 0);
    EXPECT_EQ(sword -> getItemType(), 2);
    EXPECT_EQ(sword -> getWeaponDamageBonus(), 0);
    EXPECT_EQ(sword -> getWeaponMovementBonus(), 0);
    EXPECT_EQ(sword -> getWeaponMovementSpeedModifier(), 1.10);
}

TEST(SwordConstructor, testSwordFullContructor)
{
    Sword* sword = new Sword("Longsword", 15, 30, 25);

    EXPECT_EQ(sword -> getItemName(), "Longsword");
    EXPECT_EQ(sword -> getItemCost(), 15);
    EXPECT_EQ(sword -> getItemType(), 2);
    EXPECT_EQ(sword -> getWeaponDamageBonus(), 30);
    EXPECT_EQ(sword -> getWeaponMovementBonus(), 25);
    EXPECT_EQ(sword -> getWeaponMovementSpeedModifier(), 1.10);
}

//DERIVED GET FUNCTIONS : WEAPON AND ITEM

TEST(SwordGetFunctions, testSwordGetItemName)
{
    Sword* sword = new Sword("Energized Blade", 90, 80, 40);

    EXPECT_EQ(sword -> getItemName(), "Energized Blade");
}

TEST(SwordGetFunctions, testSwordGetItemCost)   //NEW
{
    Sword* sword = new Sword("Energized Blade", 90, 80, 40);

    EXPECT_EQ(sword -> getItemCost(), 90);
}

TEST(SwordGetFunctions, testSwordGetItemType)   //NEW
{
    Sword* sword = new Sword("Energized Blade", 90, 80, 40);

    EXPECT_EQ(sword -> getItemType(), 2);
}

TEST(SwordGetFunctions, testSwordGetDamageBonus)
{
    Sword* sword = new Sword("Energized Blade", 90, 80, 40);

    EXPECT_EQ(sword -> getWeaponDamageBonus(), 80);
}

TEST(SwordGetFunctions, testSwordGetMovementBonus)
{
    Sword* sword = new Sword("Maneater", 200, 150, 100);

    EXPECT_EQ(sword -> getWeaponMovementBonus(), 100);
}

TEST(SwordGetFunctions, testSwordGetMovementSpeedModifier)
{
    Sword* sword = new Sword("Maneater", 200, 150, 100);

    EXPECT_EQ(sword -> getWeaponMovementSpeedModifier(), 1.10);
}

//DERIVED MODIFER FUNCTIONS : WEAPON AND ITEM

TEST(SwordModifiers, testSwordItemNameModifier)
{
    Sword* sword = new Sword("Maneater", 200, 150, 100);

    sword -> setItemName("Red Imposter");
    EXPECT_EQ(sword -> getItemName(), "Red Imposter");
}

TEST(SwordModifiers, testSwordItemCostModifier) //NEW
{
    Sword* sword = new Sword("Maneater", 200, 150, 100);

    sword -> setItemCost(9000);
    EXPECT_EQ(sword -> getItemCost(), 9000);
}

TEST(SwordModifiers, testSwordItemTypeModifier) //NEW
{
    Sword* sword = new Sword("Maneater", 200, 150, 100);

    sword -> setItemType(15345);
    EXPECT_EQ(sword -> getItemType(), 15345);
}

TEST(SwordModifiers, testSwordDamageBonusModifier)
{
    Sword* sword = new Sword("Maneater", 200, 150, 100);

    sword -> setWeaponDamageBonus(300);
    EXPECT_EQ(sword -> getWeaponDamageBonus(), 300);
}

TEST(SwordModifiers, testSwordMovementBonusModifier)
{
    Sword* sword = new Sword("Green Sword", 40, 50, 50);

    sword -> setWeaponMovementBonus(999);
    EXPECT_EQ(sword -> getWeaponMovementBonus(), 999);
}

TEST(SwordModifiers, testSwordMovementSpeedModifierModifier)
{
    Sword* sword = new Sword("Green Sword", 40, 50, 50);

    sword -> setWeaponMovementSpeedModifier(1.20);
    EXPECT_NE(sword -> getWeaponMovementSpeedModifier(), 1.20);
    EXPECT_EQ(sword -> getWeaponMovementSpeedModifier(), 1.10);
}