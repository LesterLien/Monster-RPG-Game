#include "../header/Character.h"
#include "../header/Hero.h"
#include "../header/Enemy.h"
#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

TEST(enemyTests, testEnemyConstructor) {

	Enemy *testEnemy = new Enemy(1);
	
	std::string enemyName = testEnemy -> getName();
	std::string enemyNameExpected = "Undead Knight";

	EXPECT_EQ(enemyName, enemyNameExpected); 

	EXPECT_EQ(testEnemy->getMovementSpeed(), 15); 
	EXPECT_EQ(testEnemy-> getAttackDamage(), 20);


	Enemy *testEnemyA = new Enemy(2);

	std::string enemyNameA = testEnemyA -> getName();
	std::string enemyNameExpectedA = "Shrieker";

	EXPECT_EQ(enemyNameA, enemyNameExpectedA); 
	EXPECT_EQ(testEnemyA->getMovementSpeed(), 20); 
	EXPECT_EQ(testEnemyA-> getAttackDamage(), 25);


	Enemy *testEnemyB = new Enemy(3);

	std::string enemyNameB = testEnemyB -> getName();
	std::string enemyNameExpectedB = "Minotaur";

	EXPECT_EQ(enemyNameB, enemyNameExpectedB); 
	EXPECT_EQ(testEnemyB->getMovementSpeed(), 10); 
	EXPECT_EQ(testEnemyB-> getAttackDamage(), 30);


	Enemy *testEnemyC = new Enemy(4);

	std::string enemyNameC = testEnemyC -> getName();
	std::string enemyNameExpectedC = "Wandering Wolf";

	EXPECT_EQ(enemyNameC, enemyNameExpectedC); 
	EXPECT_EQ(testEnemyC->getMovementSpeed(), 30); 
	EXPECT_EQ(testEnemyC-> getAttackDamage(), 15);

}



TEST(enemyTests, testAccessorEnemyDamage) {

	Enemy *testEnemy = new Enemy(1);

	EXPECT_EQ(testEnemy->getEnemyDamage(), 20);


	Enemy *testEnemyA = new Enemy(2);

	EXPECT_EQ(testEnemyA->getEnemyDamage(), 25);

	
	Enemy *testEnemyB = new Enemy(3); 

	EXPECT_EQ(testEnemyB->getEnemyDamage(), 30);

	
	Enemy *testEnemyC = new Enemy(4); 
	
	EXPECT_EQ(testEnemyC->getEnemyDamage(), 15); 

}


TEST(enemyTests, testAccessorGoldReward) {
	
	Enemy *testEnemy = new Enemy(1);

	EXPECT_EQ(testEnemy->getGoldReward(), 10); 


	Enemy *testEnemyA = new Enemy(2);

	EXPECT_EQ(testEnemyA->getGoldReward(), 10); 

	
	Enemy *testEnemyB = new Enemy(3);

	EXPECT_EQ(testEnemyB->getGoldReward(), 10); 


	Enemy *testEnemyC = new Enemy(4);

	EXPECT_EQ(testEnemyC->getGoldReward(), 10); 


	//maybe 

	Enemy *testEnemyD = new Enemy(2); 

	Hero *testHero = new Hero("testHero"); 
	
    testEnemyD -> rewardDeath(testHero); 

	EXPECT_EQ(testHero->getGoldAmount(), 10); 
	
}



TEST(enemyTests, testAccessorExpReward) {
	
	Enemy *testEnemy = new Enemy(1);

	EXPECT_EQ(testEnemy->getExpReward(), 10); 


	Enemy *testEnemyA = new Enemy(2);

	EXPECT_EQ(testEnemyA->getExpReward(), 10); 

	
	Enemy *testEnemyB = new Enemy(3);

	EXPECT_EQ(testEnemyB->getExpReward(), 10); 


	Enemy *testEnemyC = new Enemy(4);

	EXPECT_EQ(testEnemyC->getExpReward(), 10);


	//maybe 

	Enemy *testEnemyD = new Enemy(2); 

	Hero *testHero = new Hero("testHero"); 
	
	testEnemyD -> rewardDeath(testHero); 

	EXPECT_EQ(testHero->getCurrentExp(), 10); 
	
}



TEST(enemyTests, testAccessorAttackBlocked) {

	Enemy *testEnemy = new Enemy(1); 

	EXPECT_EQ(testEnemy->attackBlocked(), 0); 


	Enemy *testEnemyA = new Enemy(2); 

	EXPECT_EQ(testEnemyA->attackBlocked(), 0); 

	
	Enemy *testEnemyB = new Enemy(3); 

	EXPECT_EQ(testEnemyB->attackBlocked(), 0); 


	Enemy *testEnemyC = new Enemy(4); 

	EXPECT_EQ(testEnemyC->attackBlocked(), 0); 


}


TEST(enemyTests, testModifierRewardDeath) {

	Enemy *testEnemy = new Enemy(1); 
	Hero *testHero = new Hero("testHero"); 

	testEnemy -> rewardDeath(testHero);

	EXPECT_EQ(testHero->getGoldAmount(), 10); 
	EXPECT_EQ(testHero->getCurrentExp(), 10); 


	Enemy *testEnemyA = new Enemy(2); 
	Hero *testHeroA = new Hero("testHeroA"); 

	testEnemyA -> rewardDeath(testHeroA);

	EXPECT_EQ(testHeroA->getGoldAmount(), 10); 
	EXPECT_EQ(testHeroA->getCurrentExp(), 10); 


	//testing reward death 2 times 
	Enemy *testEnemyB = new Enemy(1); 
	Hero *testHeroB = new Hero("testHeroB"); 

	testEnemyB -> rewardDeath(testHeroB);
	testEnemyB -> rewardDeath(testHeroB);

	EXPECT_EQ(testHeroB->getGoldAmount(), 20); 
	EXPECT_EQ(testHeroB->getCurrentExp(), 20); 

}

TEST(enemyTests, testModifierChangeBlockedStatus) {

	Enemy *testEnemy = new Enemy(1);

	testEnemy -> changeBlockedStatus();

	EXPECT_EQ(testEnemy->attackBlocked(), 1); 



	Enemy *testEnemyA = new Enemy(2); 

	testEnemyA -> changeBlockedStatus(); 
	
	EXPECT_EQ(testEnemyA->attackBlocked(), 1); 
	



	Enemy *testEnemyB = new Enemy(3); 

	testEnemyB -> changeBlockedStatus(); 
	
	EXPECT_EQ(testEnemyB->attackBlocked(), 1); 



	Enemy *testEnemyC = new Enemy(4); 

	testEnemyC -> changeBlockedStatus(); 
	
	EXPECT_EQ(testEnemyC->attackBlocked(), 1); 



	//testing changeBlocked-status 2 times 

	Enemy *testEnemyD = new Enemy(5); 

	testEnemyD -> changeBlockedStatus();
	
	testEnemyD -> changeBlockedStatus();

	EXPECT_EQ(testEnemyD->attackBlocked(), 0); 

	
}

