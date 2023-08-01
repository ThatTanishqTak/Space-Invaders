#include "game.h"

Game::Game()
{
	initVariable();
	initTexture();
	initScreen();

	player_obj = new Player(this);
	grp_obj = new Graphics();
}

Game::~Game()
{
	unload();
	
	delete player_obj;
	delete grp_obj;

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
}

void Game::render()
{
	BeginDrawing();
	ClearBackground(BLACK);

	grp_obj->render();
	player_obj->render();


	EndDrawing();
}

void Game::unload()
{

}