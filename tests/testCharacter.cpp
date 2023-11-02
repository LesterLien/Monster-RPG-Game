#include "gtest/gtest.h"
#include "../header/GameController.h"
#include "../header/"
#include <iostream>

TEST(characterTests, testConstructor) {
    Character *testCharacter = new Character("test");

    EXPECT_EQ(testCharacter->getName(), "test");
    EXPECT_EQ(testCharacter->getHealth(), 100);
    EXPECT_EQ(testCharacter->getAttackDamage(), 0);
    EXPECT_EQ(testCharacter->getCriticalAttackChance(), 0);
    EXPECT_EQ(testCharacter->getMovementSpeed(), 0);
}

TEST(characterTests, testAccessorName) {
    Character *testCharacter = new Character("test");

    EXPECT_EQ(testCharacter->getName(), "test");
}

TEST(characterTests, testAccessorHealth) {
    Character *testCharacter = new Character("test");

    EXPECT_EQ(testCharacter->getHealth(), 100);
}

TEST(characterTests, testAccessorAttackDamage) {
    Character *testCharacter = new Character("test");

    EXPECT_EQ(testCharacter->getAttackDamage(), 0);
}

// TEST(characterTests, testAccessor)

// // TEST(characterTests, testConstructor) {

// // }