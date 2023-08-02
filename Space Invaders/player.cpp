#include "player.h"
#include "game.h"

Player::Player(Game* game)
{
	game_obj = game;

	initTexture();
	initVariables();
}

Player::~Player()
{
	unload();
}

void Player::update()
{
	if (IsKeyDown(KEY_A))
		playerPos.x -= moveSpeed;
	else if (IsKeyDown(KEY_D))
		playerPos.x += moveSpeed;
	if (IsKeyDown(KEY_W))
		playerPos.y -= moveSpeed;
	else if (IsKeyDown(KEY_S))
		playerPos.y += moveSpeed;

	if (IsKeyDown(KEY_SPACE))
		laserPos.y -= moveSpeed;

	if (IsKeyDown(KEY_SPACE) && !isShooting)
	{
		isShooting = true;
		laserPos = { playerPos.x + playerIdle.width / 2.0f - playerLaser.width / 2.0f, playerPos.y };
	}

	if (isShooting)
	{
		laserPos.y -= laserSpeed;
		if (laserPos.y + playerLaser.height <= 0)
			isShooting = false;
	}

	if (playerPos.x <= 0.0f)
		playerPos.x = 0.0f;
	if (playerPos.x + playerIdle.width >= game_obj->windowWidth)
		playerPos.x = game_obj->windowWidth - playerIdle.width;
	if (playerPos.y <= 0.0f)
		playerPos.y = 0.0f;
	if (playerPos.y + playerIdle.height >= game_obj->windowHeight)
		playerPos.y = game_obj->windowHeight - playerIdle.height;
}

void Player::render()
{
	if (IsKeyDown(KEY_A))
		DrawTexture(playerLeft, static_cast<float>(playerPos.x), static_cast<float>(playerPos.y), WHITE);
	else if (IsKeyDown(KEY_D))
		DrawTexture(playerRight, static_cast<float>(playerPos.x), static_cast<float>(playerPos.y), WHITE);
	else
		DrawTexture(playerIdle, static_cast<int>(playerPos.x), static_cast<int>(playerPos.y), WHITE);

	if (isShooting) 
		DrawTexture(playerLaser, static_cast<float>(laserPos.x), static_cast<float>(laserPos.y), WHITE);
}

void Player::initVariables()
{
	moveSpeed = 10.0f;
	playerPos = { game_obj->windowWidth / 2.0f, game_obj->windowHeight - static_cast<float>(playerIdle.height) };
	laserPos = { playerIdle.width / 2.0f, static_cast<float>(playerIdle.height) + playerLaser.height };
	isShooting = false;
	laserSpeed = 15.0f;
}

void Player::initTexture()
{
	playerIdle = LoadTexture("textures/Player/player.png");
	playerLeft = LoadTexture("textures/Player/playerLeft.png");
	playerRight = LoadTexture("textures/Player/playerRight.png");
	playerShield = LoadTexture("textures/Player/shield.png");
	playerLife = LoadTexture("textures/Player/life.png");
	playerDamaged = LoadTexture("textures/Player/playerDamaged.png");
	playerLaser = LoadTexture("textures/Player/laserRed.png");
	playerLaserShoot = LoadTexture("textures/Player/laserRedShot.png");
}

void Player::unload()
{
	UnloadTexture(playerIdle);
	UnloadTexture(playerLeft);
	UnloadTexture(playerRight);
	UnloadTexture(playerShield);
	UnloadTexture(playerLife);
	UnloadTexture(playerDamaged);
	UnloadTexture(playerLaser);
	UnloadTexture(playerLaserShoot);
}