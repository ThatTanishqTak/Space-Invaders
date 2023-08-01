#pragma once

#include "raylib.h"

class Game;

class Graphics
{
public:
	Graphics();
	~Graphics();

	void initVariable();
	void initTexture();

	void update();
	void render();

private:
	Texture2D background;
	Texture2D speedLine;

	void unload();
};