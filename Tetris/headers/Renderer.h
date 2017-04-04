#pragma once
#include <string>
#include <cstdint>

#include <SDL.h>
#include <SDL_image.h>

#include "Logger.h"
#include "Texture.h"

#include "constants.h"
#include "enums.h"

enum class EButtonType;
enum class EScreenPosition;

class Texture;

class Renderer
{
private:
	Logger logger;
	SDL_Renderer* rendererSDL;
	SDL_Window* gameWindow{ NULL };
	SDL_Texture* savedModifiedTexture;
	
	Texture dummyTexture;
	
	int texturesCount;

public:
	Renderer();
	~Renderer();
	void InitSDL();
	void InitSDLRenderer();
	
	void Clear();
	void AddToQueue(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect);
	void Render();
};

