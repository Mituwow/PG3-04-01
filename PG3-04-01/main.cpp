#include <iostream>
#include "Enemy.h"


int main() {

	Enemy* enemy = new Enemy();
	enemy->Update();	
	enemy->~Enemy();

	return 0;
}