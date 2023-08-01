#pragma once

#include "raylib.h"
#include "player.h"

class Game
{
public:
	Game();
	~Game();

	int windowWidth, windowHeight;

	void run();
	void update();
	void render();

private:
	Player* player_obj;

	void initVariable();
	void initScreen();
	void initTexture();
	void unload();

};