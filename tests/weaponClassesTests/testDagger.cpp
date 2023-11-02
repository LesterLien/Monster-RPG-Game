#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"
#include "../../header/weaponClassesHeader/Dagger.h"
#include "gtest/gtest.h"

using ::Item;
using ::Weapon;
using ::Dagger;

using std::string;

//CONSTRUCTOR TESTS
TEST(DaggerConstructor, testDaggerBasicConstructor)
{
    Dagger* dagger = new Dagger();

    EXPECT_EQ(dagger -> getItemName(), "Dagger");
    EXPECT_EQ(dagger -> getItemCost(), 0);
    EXPECT_EQ(dagger -> getItemType(), 2);
    EXPECT_EQ(dagger -> getWeaponDamageBonus(), 0);
    EXPECT_EQ(dagger -> getWeaponMovementBonus(), 0);
    EXPECT_EQ(dagger -> getWeaponMovementSpeedModifier(), 1.50);
}

TEST(DaggerConstructor, testDaggerFullContructor)
{
    Dagger* dagger = new Dagger("Slick Dagger", 40, 30, 20);

    EXPECT_EQ(dagger -> getItemName(), "Slick Dagger");
    EXPECT_EQ(dagger -> getItemCost(), 40);
    EXPECT_EQ(dagger -> getItemType(), 2);
    EXPECT_EQ(dagger -> getWeaponDamageBonus(), 30);
    EXPECT_EQ(dagger -> getWeaponMovementBonus(), 20);
    EXPECT_EQ(dagger -> getWeaponMovementSpeedModifier(), 1.50);
}

//DERIVED GET FUNCTIONS : WEAPON AND ITEM

TEST(DaggerGetFunctions, testDaggerGetItemName)
{
    Dagger* dagger = new Dagger("Crimson Slayer", 70, 30, 30);

    EXPECT_EQ(dagger -> getItemName(), "Crimson Slayer");
}

TEST(DaggerGetFunctions, testDaggerGetItemCost) //NEW
{
    Dagger* dagger = new Dagger("Crimson Slayer", 70, 30, 30);

    EXPECT_EQ(dagger -> getItemCost(), 70);
}

TEST(DaggerGetFunctions, testDaggerGetItemType) //NEW
{
    Dagger* dagger = new Dagger("Crimson Slayer", 70, 30, 30);

    EXPECT_EQ(dagger -> getItemType(), 2);
}

TEST(DaggerGetFunctions, testDaggerGetDamageBonus)
{
    Dagger* dagger = new Dagger("Crimson Slayer", 90, 120, 100);

    EXPECT_EQ(dagger -> getWeaponDamageBonus(), 120);
}

TEST(DaggerGetFunctions, testDaggerGetMovementBonus)
{
    Dagger* dagger = new Dagger("Red Dagger", 100, 20, 50);

    EXPECT_EQ(dagger -> getWeaponMovementBonus(), 50);
}

TEST(DaggerGetFunctions, testDaggerGetMovementSpeedModifier)
{
    Dagger* dagger = new Dagger("Quick Crimson", 150, 100, 200);

    EXPECT_EQ(dagger -> getWeaponMovementSpeedModifier(), 1.50);
}

//DERIVED MODIFER FUNCTIONS : WEAPON AND ITEM

TEST(DaggerModifiers, testDaggerItemNameModifier)
{
    Dagger* dagger = new Dagger("Slick Dagger", 15,20, 10);

    dagger -> setItemName("Steel Dagger");
    EXPECT_EQ(dagger -> getItemName(), "Steel Dagger");
}

TEST(DaggerModifiers, testDaggerItemCostModifier)   //NEW
{
    Dagger* dagger = new Dagger("Slick Dagger", 15, 20, 10);

    dagger -> setItemCost(912);
    EXPECT_EQ(dagger -> getItemCost(), 912);
}

TEST(DaggerModifiers, testDaggerItemTypeModifier)   //NEW
{
    Dagger* dagger = new Dagger("Slick Dagger", 15, 20, 10);

    dagger -> setItemType(124);
    EXPECT_EQ(dagger -> getItemType(), 124);
}

TEST(DaggerModifiers, testDaggerDamageBonusModifier)
{
    Dagger* dagger = new Dagger("Slick Dagger", 15, 20, 10);

    dagger -> setWeaponDamageBonus(100);
    EXPECT_EQ(dagger -> getWeaponDamageBonus(), 100);
}

TEST(DaggerModifiers, testDaggerMovementBonusModifier)
{
    Dagger* dagger = new Dagger("Wooden Dagger", 25, 20, 10);

    dagger -> setWeaponMovementBonus(20);
    EXPECT_EQ(dagger -> getWeaponMovementBonus(), 20);
}

TEST(DaggerModifiers, testDaggerMovementSpeedModifierModifier)
{
    Dagger* dagger = new Dagger("Wooden Dagger", 25, 20, 10);

    dagger -> setWeaponMovementSpeedModifier(2.00);
    EXPECT_NE(dagger -> getWeaponMovementSpeedModifier(), 2.00);
    EXPECT_EQ(dagger -> getWeaponMovementSpeedModifier(), 1.50);
}