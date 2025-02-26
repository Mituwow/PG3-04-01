#include "Enemy.h"
#include <iostream>


Enemy::Enemy()
{
	enemyMode = -1;
}

Enemy::~Enemy()
{
}

void Enemy::approach()
{
	enemyMode = static_cast<size_t>(Phase::APPROACH);
	std::cout << "敵が接近してきました" << std::endl;
}

void Enemy::attack()
{
	enemyMode = static_cast<size_t>(Phase::ATTACK);
	std::cout << "敵の攻撃です" << std::endl;
}

void Enemy::escape()
{
	enemyMode = static_cast<size_t>(Phase::ESCAPE);
	std::cout << "敵が先頭から離脱しました" << std::endl;
}

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::approach,
	&Enemy::attack,
	&Enemy::escape
};

void Enemy::Update()
{

	for (int i = static_cast<size_t>(Phase::APPROACH); i <= static_cast<size_t>(Phase::ESCAPE); i++) {
		(this->*spFuncTable[i])();
		std::cout << enemyMode << std::endl;
	}
}