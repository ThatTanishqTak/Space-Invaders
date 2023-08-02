#include "enemy.h"
#include "game.h"

Enemy::Enemy(Game* game)
{
	game_ene_obj = game;

	initTexture();
	initVariable();
}

Enemy::~Enemy()
{
	unload();
}

void Enemy::initTexture()
{
	enemyShip = LoadTexture("textures/Enemy/enemyShip.png");
	enemyUFO = LoadTexture("textures/Enemy/enemyUFO.png");
	enemyLaser = LoadTexture("textures/Enemy/laserGreen.png");
	enemyLaserShoot = LoadTexture("textures/Enemy/laserGreenShot.png");
	meteorBig = LoadTexture("textures/Enemy/meteorBig.png");
	meteorSmall = LoadTexture("textures/Enemy/meteorSmall.png");

}

void Enemy::initVariable()
{

}

void Enemy::update()
{

}

void Enemy::render()
{
	DrawTexture(enemyShip, game_ene_obj->windowWidth / 2, 0, WHITE);
}

void Enemy::unload()
{
	UnloadTexture(enemyShip);
	UnloadTexture(enemyUFO);
	UnloadTexture(enemyLaser);
	UnloadTexture(enemyLaserShoot);
	UnloadTexture(meteorBig);
	UnloadTexture(meteorSmall);
}
