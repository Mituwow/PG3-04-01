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
	std::cout << "�G���ڋ߂��Ă��܂���" << std::endl;
}

void Enemy::attack()
{
	enemyMode = static_cast<size_t>(Phase::ATTACK);
	std::cout << "�G�̍U���ł�" << std::endl;
}

void Enemy::escape()
{
	enemyMode = static_cast<size_t>(Phase::ESCAPE);
	std::cout << "�G���擪���痣�E���܂���" << std::endl;
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