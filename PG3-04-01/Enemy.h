#pragma once

enum class Phase
{
	APPROACH,
	ATTACK,
	ESCAPE
};

class Enemy {
public:
	Enemy();
	~Enemy();
	
	void approach();
	void attack();
	void escape();
	void Update();

private:
	static void (Enemy::* spFuncTable[])();
	int enemyMode;
};