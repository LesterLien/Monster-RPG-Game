#include "../header/Enemy.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

Enemy::Enemy() {
    this -> attackIsBlocked = false;
    this -> enemyDamage = 0; 
    this -> goldReward = 10; 
    this -> expReward = 10;
}

Enemy::Enemy(int enemyType) {

    this -> attackIsBlocked = false;
    this -> enemyDamage = 0; 
    this -> goldReward = 10; 
    this -> expReward = 10;

    if (enemyType == 1) {
        setName("Undead Knight");
        setMovementSpeed(15);
        setAttackDamage(20);
    }
    else if (enemyType == 2) {
        setName("Shrieker");
        setMovementSpeed(20);
        setAttackDamage(25);
    }
    else if (enemyType == 3) {
        setName("Minotaur");
        setMovementSpeed(10);
        setAttackDamage(30);
    }
    else {
        setName("Wandering Wolf");
        setMovementSpeed(30);
        setAttackDamage(15);
    }
}

Enemy::~Enemy() {}

int Enemy::getEnemyDamage() {
    return getAttackDamage();
}

int Enemy::getGoldReward() {
    return goldReward;
}

int Enemy::getExpReward() {
    return expReward;
}

bool Enemy::attackBlocked() {
    return attackIsBlocked;
}

void Enemy::rewardDeath(Hero *player) {
    player->addGoldAmount(goldReward);
    player->addExperience(expReward);
}

void Enemy::changeBlockedStatus() {

    if (attackIsBlocked)
    {
        attackIsBlocked = !(attackIsBlocked);
    }
    else
    {
        attackIsBlocked = 1;
    }
    
}