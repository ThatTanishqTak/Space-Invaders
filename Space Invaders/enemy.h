#pragma once

#include "raylib.h"

class Game;

class Enemy
{
public:
	Enemy(Game* game);
	~Enemy();

	void initTexture();
	void initVariable();

	void update();
	void render();

private:
	Texture2D enemyShip;
	Texture2D enemyUFO;
	Texture2D enemyLaser;
	Texture2D enemyLaserShoot;
	Texture2D meteorBig;
	Texture2D meteorSmall;

	Game* game_ene_obj;

	void unload();
};