#include "game.h"

Game::Game()
{
	initVariable();
	initTexture();
	initScreen();

	player_obj = new Player(this);
}

Game::~Game()
{
	unload();
	
	delete player_obj;

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
	player_obj->update();
}

void Game::render()
{
	BeginDrawing();
	ClearBackground(BLACK);

	player_obj->render();

	EndDrawing();
}

void Game::unload()
{

}