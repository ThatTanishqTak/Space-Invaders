#pragma once

#include "raylib.h"
#include <iostream>
#include <vector>

class Graphics
{
public:
	Graphics();
	~Graphics();

	std::vector<Vector2> spawnedLines;

	void initVariable();
	void initTexture();

	void spawnLine();

	void update();
	void render();

private:
	float currentTime;

	float speedLineSpeed;
	float spawnInterval;
	float lastSpawnTime;

	float randomX;
	float randomY;

	Vector2 speedLinePos;

	Texture2D background;
	Texture2D speedLine;
	Texture2D starBig;
	Texture2D starSmall;

	void unload();
};