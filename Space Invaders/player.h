#pragma once

#include "raylib.h"

class Game;

class Player
{
public:
	Player(Game* game);
	~Player();

	void initVariables();
	void initTexture();

	void update();
	void render();

private:
	Vector2 playerPos;
	Vector2 laserPos;

	float moveSpeed;
	float laserSpeed;

	bool isShooting;

	Game* game_obj;

	Texture2D playerIdle;
	Texture2D playerLeft;
	Texture2D playerRight;
	Texture2D playerShield;
	Texture2D playerLife;
	Texture2D playerDamaged;
	Texture2D playerLaser;
	Texture2D playerLaserShoot;

	void unload();
};