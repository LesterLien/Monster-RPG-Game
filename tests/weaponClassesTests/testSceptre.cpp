#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"
#include "../../header/weaponClassesHeader/Sceptre.h"
#include "gtest/gtest.h"

using ::Item;
using ::Weapon;
using ::Sceptre;

using std::string;

//CONSTRUCTOR TESTS
TEST(SceptreConstructor, testSceptreBasicConstructor)
{
    Sceptre* sceptre = new Sceptre();

    EXPECT_EQ(sceptre -> getItemName(), "Sceptre");
    EXPECT_EQ(sceptre -> getItemCost(), 0);
    EXPECT_EQ(sceptre -> getItemType(), 2);
    EXPECT_EQ(sceptre -> getWeaponDamageBonus(), 0);
    EXPECT_EQ(sceptre -> getWeaponMovementBonus(), 0);
    EXPECT_EQ(sceptre -> getWeaponMovementSpeedModifier(), 1.00);
}

TEST(SceptreConstructor, testSceptreFullContructor)
{
    Sceptre* sceptre = new Sceptre("Traditional Staff", 20, 50, 5);

    EXPECT_EQ(sceptre -> getItemName(), "Traditional Staff");
    EXPECT_EQ(sceptre -> getItemCost(), 20);
    EXPECT_EQ(sceptre -> getItemType(), 2);
    EXPECT_EQ(sceptre -> getWeaponDamageBonus(), 50);
    EXPECT_EQ(sceptre -> getWeaponMovementBonus(), 5);
    EXPECT_EQ(sceptre -> getWeaponMovementSpeedModifier(), 1.00);
}

//DERIVED GET FUNCTIONS : WEAPON AND ITEM

TEST(SceptreGetFunctions, testSceptreGetItemName)
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    EXPECT_EQ(sceptre -> getItemName(), "Dark Reaper");
}

TEST(SceptreGetFunctions, testSceptreGetItemCost)   //NEW
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    EXPECT_EQ(sceptre -> getItemCost(), 100);
}

TEST(SceptreGetFunctions, testSceptreGetItemType)   //NEW
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    EXPECT_EQ(sceptre -> getItemType(), 2);
}

TEST(SceptreGetFunctions, testSceptreGetDamageBonus)
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    EXPECT_EQ(sceptre -> getWeaponDamageBonus(), 70);
}

TEST(SceptreGetFunctions, testSceptreGetMovementBonus)
{
    Sceptre* sceptre = new Sceptre("Elsraniar", 200, 100, 5);

    EXPECT_EQ(sceptre -> getWeaponMovementBonus(), 5);
}

TEST(SceptreGetFunctions, testSceptreGetMovementSpeedModifier)
{
    Sceptre* sceptre = new Sceptre("Elsraniar", 200, 100, 200);

    EXPECT_EQ(sceptre -> getWeaponMovementSpeedModifier(), 1.00);
}

//DERIVED MODIFER FUNCTIONS : WEAPON AND ITEM

TEST(SceptreModifiers, testSceptreItemNameModifier)
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    sceptre -> setItemName("Among Us");
    EXPECT_EQ(sceptre -> getItemName(), "Among Us");
}

TEST(SceptreModifiers, testSceptreItemCostModifier) //NEW
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    sceptre -> setItemCost(200);
    EXPECT_EQ(sceptre -> getItemCost(), 200);
}

TEST(SceptreModifiers, testSceptreItemTypeModifier) //NEW
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    sceptre -> setItemType(123);
    EXPECT_EQ(sceptre -> getItemType(), 123);
}

TEST(SceptreModifiers, testSceptreDamageBonusModifier)
{
    Sceptre* sceptre = new Sceptre("Dark Reaper", 100, 70, 0);

    sceptre -> setWeaponDamageBonus(200);
    EXPECT_EQ(sceptre -> getWeaponDamageBonus(), 200);
}

TEST(SceptreModifiers, testSceptreMovementBonusModifier)
{
    Sceptre* sceptre = new Sceptre("Basic Sceptre", 8, 50, 10);

    sceptre -> setWeaponMovementBonus(30);
    EXPECT_EQ(sceptre -> getWeaponMovementBonus(), 30);
}

TEST(SceptreModifiers, testSceptreMovementSpeedModifierModifier)
{
    Sceptre* sceptre = new Sceptre("Basic Sceptre", 8, 50, 10);

    sceptre -> setWeaponMovementSpeedModifier(0.80);
    EXPECT_NE(sceptre -> getWeaponMovementSpeedModifier(), 0.80);
    EXPECT_EQ(sceptre -> getWeaponMovementSpeedModifier(), 1.00);
}