#include "graphics.h"

Graphics::Graphics()
{
	initTexture();
	initVariable();
}

Graphics::~Graphics()
{
	unload();
}

void Graphics::initVariable()
{
	speedLineSpeed = 20.0f;
	
	spawnInterval = 1000.0f;
	lastSpawnTime = GetTime();
}

void Graphics::initTexture()
{
	background = LoadTexture("textures/Background/background.png");
	speedLine = LoadTexture("textures/Background/speedLine.png");
	starBig = LoadTexture("textures/Background/starBig.png");
	starSmall = LoadTexture("textures/Background/starSmall.png");
}

void Graphics::spawnLine()
{
	currentTime = GetTime();
	if (currentTime - lastSpawnTime >= spawnInterval)
	{
		randomX = GetRandomValue(0, 1080 - speedLine.width);
		randomY = GetRandomValue(720 - speedLine.height, 720 - speedLine.height);

		spawnedLines.push_back({ randomX, randomY });
		lastSpawnTime = currentTime;
	}

	speedLinePos.y += speedLineSpeed;
	if (speedLinePos.y >= 720)
		speedLinePos.y = -static_cast<float>(speedLine.height);
}

void Graphics::update()
{
	spawnLine();
}

void Graphics::render()
{
	DrawTexturePro(background, { 0, 0, 1080, 720 }, { 0, 0, 1080, 720 }, { 0, 0 }, 0.0f, WHITE);
	for(const auto& pos : spawnedLines)
	{
		DrawTexture(speedLine, static_cast<int>(pos.x), static_cast<int>(pos.y), WHITE);
	}
}

void Graphics::unload()
{
	UnloadTexture(background);
	UnloadTexture(speedLine);
	UnloadTexture(starBig);
	UnloadTexture(starSmall);
}
