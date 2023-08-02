#pragma once

#include "raylib.h"

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
	float speedLineSpeed;
	
	Vector2 speedLinePos;

	Texture2D background;
	Texture2D speedLine;
	Texture2D starBig;
	Texture2D starSmall;

	void unload();
};