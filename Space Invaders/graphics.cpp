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

}

void Graphics::initTexture()
{
	background = LoadTexture("textures/Background/starBackground.png");
	speedLine = LoadTexture("textures/Background/speedLine.png");
}

void Graphics::update()
{

}

void Graphics::render()
{
	DrawTextureEx(background, { 0,0 }, 0.0f, 5.0f, WHITE);
}

void Graphics::unload()
{
	UnloadTexture(background);
	UnloadTexture(speedLine);
}
