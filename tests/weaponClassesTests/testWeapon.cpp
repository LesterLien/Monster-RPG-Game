#include "../../header/Item.h"
#include "../../header/weaponClassesHeader/Weapon.h"
#include "gtest/gtest.h"

using ::Item;
using ::Weapon;
using std::string;

//CONSTRUCTOR TESTS
TEST(WeaponConstructor, testWeaponBasicContructor)
{
    Weapon* weapon = new Weapon();

    EXPECT_EQ(weapon -> getItemName(), "Default Weapon");
    EXPECT_EQ(weapon -> getWeaponDamageBonus(), 0);
    EXPECT_EQ(weapon -> getWeaponMovementBonus(), 0);
}

TEST(WeaponConstructor, testWeaponParameterConstructor)
{
    Weapon* weapon = new Weapon(25,10);
    
    EXPECT_EQ(weapon -> getItemName(), "Default Weapon");
    EXPECT_EQ(weapon -> getWeaponDamageBonus(), 25);
    EXPECT_EQ(weapon -> getWeaponMovementBonus(), 10);
}

TEST(WeaponConstructor, testWeaponAlmostFullConstructor)
{
    Weapon* weapon = new Weapon("Destroyer", 50, 5);
    
    EXPECT_EQ(weapon -> getItemName(), "Destroyer");
    EXPECT_EQ(weapon -> getWeaponDamageBonus(), 50);
    EXPECT_EQ(weapon -> getWeaponMovementBonus(), 5);
}

TEST(WeaponConstructor, testWeaponFullConstructor)  //Modified
{
    Weapon* weapon = new Weapon("Destroyer", 20, 50, 5, 1.05);
    
    EXPECT_EQ(weapon -> getItemName(), "Destroyer");
    EXPECT_EQ(weapon -> getItemCost(), 20);
    EXPECT_EQ(weapon -> getItemType(), 2);
    EXPECT_EQ(weapon -> getWeaponDamageBonus(), 50);
    EXPECT_EQ(weapon -> getWeaponMovementBonus(), 5);
    EXPECT_EQ(weapon -> getWeaponMovementSpeedModifier(), 1.05);
}

//GET FUNCTION TESTS
TEST(WeaponGetFunctions, testWeaponGetItemNameSpaces)
{
    Weapon* weapon = new Weapon("Among Us", 20, 20);
    
    EXPECT_EQ(weapon -> getItemName(), "Among Us");
}

TEST(WeaponGetFunctions, testWeaponGetItemNameNumbers)
{
    Weapon* weapon = new Weapon("3211", 20, 20);
    
    EXPECT_EQ(weapon -> getItemName(), "3211");
}

TEST(WeaponGetFunctions, testWeaponGetItemNameSymbols)
{
    Weapon* weapon = new Weapon("&^&@!", 20, 20);
    
    EXPECT_EQ(weapon -> getItemName(), "&^&@!");
}

TEST(WeaponGetFunctions, testWeaponGetWeaponDamageBonus)
{
    Weapon* weapon = new Weapon("Apple", 30, 100, 0, 1.00);
    
    EXPECT_EQ(weapon -> getWeaponDamageBonus(), 100);
}

TEST(WeaponGetFunctions, testWeaponGetWeaponCost)    //NEW
{
    Weapon* weapon = new Weapon("Apple", 30, 100, 0, 1.00);
    
    EXPECT_EQ(weapon -> getItemCost(), 30);
}

TEST(WeaponGetFunctions, testWeaponGetWeaponType)    //NEW
{
    Weapon* weapon = new Weapon("Sword", 50, 100, 40, 1.00);
    
    EXPECT_EQ(weapon -> getItemType(), 2);
}

TEST(WeaponGetFunctions, testGetWeaponMovementBonus)
{
    Weapon* weapon = new Weapon("Sword", 50, 100, 40, 1.00);
    
    EXPECT_EQ(weapon -> getWeaponMovementBonus(), 40);
}

TEST(WeaponGetFunctions, testGetWeaponMovementSpeedModifier)
{
    Weapon* weapon = new Weapon("Sword", 50, 100, 40, 1.00);
    
    EXPECT_EQ(weapon -> getWeaponMovementSpeedModifier(), 1.00);
}

//MODIFIER FUNCTION TESTS
TEST(WeaponModifiers, testWeaponSetBonusDamage)
{
    Weapon* weapon = new Weapon("Banana", 50, 40, 20, 1.00);
    weapon -> setWeaponDamageBonus(200);

    EXPECT_EQ(weapon -> getWeaponDamageBonus(), 200);
}

TEST(WeaponModifiers, testWeaponSetBonusMovement)
{
    Weapon* weapon = new Weapon("Banana", 50, 40, 20, 1.00);
    weapon -> setWeaponMovementBonus(100);

    EXPECT_EQ(weapon -> getWeaponMovementBonus(), 100);
}

TEST(WeaponModifiers, testSetWeaponMovementSpeedModifier)
{
    Weapon* weapon = new Weapon("Banana", 50, 40, 20, 1.00);
    weapon -> setWeaponMovementSpeedModifier(1.50);

    EXPECT_EQ(weapon -> getWeaponMovementSpeedModifier(), 1.50);
}

//DERVIED MODIFER FUNCTION TESTS
TEST(WeaponDerivedModifiers, testWeaponSetItemName)
{
    Weapon* weapon = new Weapon("Almighty Sword", 50, 40, 20, 1.00);
    weapon -> setItemName("The Eater of Souls");

    EXPECT_EQ(weapon -> getItemName(), "The Eater of Souls");
}

TEST(WeaponDerivedModifiers, testWeaponSetItemCost) //NEW
{
    Weapon* weapon = new Weapon("Almighty Sword", 50, 40, 20, 1.00);
    weapon -> setItemCost(100);

    EXPECT_EQ(weapon -> getItemCost(), 100);
}

TEST(WeaponDerivedModifiers, testWeaponSetItemType) //NEW
{
    Weapon* weapon = new Weapon("Almighty Sword", 50, 40, 20, 1.00);
    weapon -> setItemType(99);

    EXPECT_EQ(weapon -> getItemType(), 99);
}