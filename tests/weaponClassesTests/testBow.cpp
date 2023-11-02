#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"
#include "../../header/weaponClassesHeader/Bow.h"
#include "gtest/gtest.h"

using ::Item;
using ::Weapon;
using ::Bow;

using std::string;

//CONSTRUCTOR TESTS
TEST(BowConstructor, testBowBasicContructor)
{
    Bow* bow = new Bow();

    EXPECT_EQ(bow -> getItemName(), "Bow");
    EXPECT_EQ(bow -> getItemCost(), 0);
    EXPECT_EQ(bow -> getItemType(), 2);
    EXPECT_EQ(bow -> getWeaponDamageBonus(), 0);
    EXPECT_EQ(bow -> getWeaponMovementBonus(), 0);
    EXPECT_EQ(bow -> getWeaponMovementSpeedModifier(), 1.25);
}

TEST(BowConstructor, testBowFullContructor)
{
    Bow* bow = new Bow("Wooden Bow", 50, 20, 10);

    EXPECT_EQ(bow -> getItemName(), "Wooden Bow");
    EXPECT_EQ(bow -> getItemCost(), 50);
    EXPECT_EQ(bow -> getItemType(), 2);
    EXPECT_EQ(bow -> getWeaponDamageBonus(), 20);
    EXPECT_EQ(bow -> getWeaponMovementBonus(), 10);
    EXPECT_EQ(bow -> getWeaponMovementSpeedModifier(), 1.25);
}

//DERIVED GET FUNCTIONS : WEAPON AND ITEM

TEST(BowGetFunctions, testBowGetItemName)
{
    Bow* bow = new Bow("Quiet Killer", 80, 20, 20);

    EXPECT_EQ(bow -> getItemName(), "Quiet Killer");
}

TEST(BowGetFunctions, testBowGetItemCost)   //NEW
{
    Bow* bow = new Bow("Quiet Killer", 80, 20, 20);

    EXPECT_EQ(bow -> getItemCost(), 80);
}

TEST(BowGetFunctions, testBowGetItemType)   //NEW
{
    Bow* bow = new Bow("Quiet Killer", 80, 20, 20);

    EXPECT_EQ(bow -> getItemType(), 2);
}

TEST(BowGetFunctions, testBowGetDamageBonus)
{
    Bow* bow = new Bow("Among Us", 70, 30, 10);

    EXPECT_EQ(bow -> getWeaponDamageBonus(), 30);
}

TEST(BowGetFunctions, testBowGetMovementBonus)
{
    Bow* bow = new Bow("Imposter", 60, 5, 15);

    EXPECT_EQ(bow -> getWeaponMovementBonus(), 15);
}

TEST(BowGetFunctions, testBowGetMovementSpeedModifier)
{
    Bow* bow = new Bow("Shapshooter", 120, 50, 5);

    EXPECT_EQ(bow -> getWeaponMovementSpeedModifier(), 1.25);
}

//DERIVED MODIFER FUNCTIONS : WEAPON AND ITEM

TEST(BowModifiers, testBowItemNameModifier)
{
    Bow* bow = new Bow("Wooden Bow", 15, 20, 10);

    bow -> setItemName("Steel Bow");
    EXPECT_EQ(bow -> getItemName(), "Steel Bow");
}

TEST(BowModifiers, testBowCostModifier)
{
    Bow* bow = new Bow("Wooden Bow", 15, 20, 10);

    bow -> setItemCost(999);
    EXPECT_EQ(bow -> getItemCost(), 999);
}

TEST(BowModifiers, testBowTypeModifier)  //NEW
{
    Bow* bow = new Bow("Wooden Bow", 15, 20, 10);

    bow -> setItemType(231);
    EXPECT_EQ(bow -> getItemType(), 231);
}

TEST(BowModifiers, testBowDamageBonusModifier)  //NEW
{
    Bow* bow = new Bow("Wooden Bow", 15, 20, 10);

    bow -> setWeaponDamageBonus(50);
    EXPECT_EQ(bow -> getWeaponDamageBonus(), 50);
}

TEST(BowModifiers, testBowMovementBonusModifier)
{
    Bow* bow = new Bow("Wooden Bow", 15, 20, 10);

    bow -> setWeaponMovementBonus(30);
    EXPECT_EQ(bow -> getWeaponMovementBonus(), 30);
}

TEST(BowModifiers, testBowMovementSpeedModifierModifier)
{
    Bow* bow = new Bow("Wooden Bow", 15, 20, 10);

    bow -> setWeaponMovementSpeedModifier(0.50);
    EXPECT_NE(bow -> getWeaponMovementSpeedModifier(), 0.50);
    EXPECT_EQ(bow -> getWeaponMovementSpeedModifier(), 1.25);
}