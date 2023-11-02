#include "../header/Hero.h"
#include "gtest/gtest.h"

TEST(heroTests, testParamaterizedContstructor) {
    Hero *testHero = new Hero("test");

    EXPECT_EQ(testHero->getName(), "test");
    EXPECT_EQ(testHero->getCurrentLevel(), 0);
    EXPECT_EQ(testHero->getCurrentExp(), 0);
    EXPECT_EQ(testHero->getGoldAmount(), 0);
}

TEST(heroTests, testSetName) {
    Hero *testHero = new Hero("test");
    
    testHero->setName("newName");
    EXPECT_EQ(testHero->getName(), "newName");
}

TEST(heroTests, testAddGoldPositiveInt) {
    Hero *hero = new Hero("test");

    hero->addGoldAmount(10);
    EXPECT_EQ(hero->getGoldAmount(), 10);
}

TEST(heroTests, testAddGoldNegativeInt) {
    Hero *hero = new Hero("test");

    hero->addGoldAmount(-10);
    EXPECT_EQ(hero->getGoldAmount(), -10);
}

TEST (heroTests, testAddExperience) {
    Hero *hero = new Hero("test");

    hero->addExperience(10);
    EXPECT_EQ(hero->getCurrentExp(), 10);
}

TEST (heroTests, testAddLevel) {
    Hero *hero = new Hero("test");

    hero->addLevel();
    EXPECT_EQ(hero->getCurrentLevel(), 1);
    EXPECT_EQ(hero->getMaxHealth(), 110);
    EXPECT_EQ(hero->getAttackDamage(), 20);
    EXPECT_EQ(hero->getMovementSpeed(), 15);
}

