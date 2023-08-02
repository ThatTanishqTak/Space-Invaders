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
	speedLinePos = { 40,-100 };
}

void Graphics::initTexture()
{
	background = LoadTexture("textures/Background/background.png");
	speedLine = LoadTexture("textures/Background/speedLine.png");
	starBig = LoadTexture("textures/Background/starBig.png");
	starSmall = LoadTexture("textures/Background/starSmall.png");
}

void Graphics::update()
{
	speedLinePos.y += speedLineSpeed;
}

void Graphics::render()
{
	DrawTexturePro(background, { 0, 0, 1080, 720 }, { 0, 0, 1080, 720 }, { 0, 0 }, 0.0f, WHITE);
	DrawTextureV(speedLine, speedLinePos, WHITE);
	DrawTexture(starBig, 540, 100, WHITE);
	DrawTexture(starSmall, 200, 100, WHITE);
}

void Graphics::unload()
{
	UnloadTexture(background);
	UnloadTexture(speedLine);
	UnloadTexture(starBig);
	UnloadTexture(starSmall);
}
