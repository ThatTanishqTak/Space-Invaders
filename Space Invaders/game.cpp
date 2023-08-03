#include "game.h"

Game::Game()
{
	initVariable();
	initTexture();
	initScreen();

	player_obj = new Player(this);
	grp_obj = new Graphics();
	ene_obj = new Enemy(this);
}

Game::~Game()
{
	unload();

	CloseWindow();
}

void Game::initVariable()
{
	windowWidth = 1080;
	windowHeight = 720;
}

void Game::initScreen()
{
	InitWindow(windowWidth, windowHeight, "Space Invaders");
	SetTargetFPS(60);
}

void Game::initTexture()
{

}


void Game::run()
{
	while (!WindowShouldClose())
	{
		update();
		render();
	}
}

void Game::update()
{
	grp_obj->update();
	player_obj->update();
	ene_obj->update();
}

void Game::render()
{
	BeginDrawing();
	ClearBackground(BLACK);

	grp_obj->render();
	player_obj->render();
	ene_obj->render();

	EndDrawing();
}

void Game::unload()
{
	delete grp_obj;
	delete player_obj;
	delete ene_obj;
}