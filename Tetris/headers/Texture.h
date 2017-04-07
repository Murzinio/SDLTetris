#pragma once
#include <string>
#include <cstdint>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>

#include "Logger.h"

struct SDL_Texture;

class Texture
{
private:
	static SDL_Renderer* sdlRenderer;
	SDL_Texture* sdlTexture;
	SDL_Rect sourceRect; // Part of the png file that the texture will use.

	Logger logger;

	SDL_Surface* CreateSurfaceFromFile(std::string path);
	SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface);

public:
	Texture();
	~Texture();

	void PassRenderer(SDL_Renderer* r);

	/*Creates SDL_Surface from a png file using CreateTextureFromSurface(),
	converts it to SDL_Texture using GetTextureFromSurface().*/
	bool LoadTexture(std::string path); 

	SDL_Texture* GetSDLTexture();
};

