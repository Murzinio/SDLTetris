#include "..\headers\Texture.h"

SDL_Renderer* Texture::sdlRenderer;

Texture::Texture()
{
	logger.Log("texture instance");
}


Texture::~Texture()
{
}

/*
	Private
*/

SDL_Texture* Texture::CreateTextureFromSurface(SDL_Surface* surface)
{
	SDL_Texture* texture{ NULL };
	uintptr_t surfaceAdress{ reinterpret_cast<uintptr_t>(surface) };

	texture = SDL_CreateTextureFromSurface(sdlRenderer, surface);

	if (!texture)
		logger.LogErrorSDL("Creating texture from surface \"" + std::to_string(surfaceAdress) + "\" failed.");

	return texture;
}

SDL_Surface* Texture::CreateSurfaceFromFile(std::string path)
{
	SDL_Surface* surface{ NULL };

	surface = IMG_Load(path.c_str());
	if (!surface)
		logger.LogErrorSDL("Creating surface from file \"" + path + "\" failed.");

	return surface;
}

/*
	Public
*/

void Texture::PassRenderer(SDL_Renderer* r)
{
	sdlRenderer = r;
}

bool Texture::LoadTexture(std::string path)
{
	std::string rootPath{"resources\\textures\\"};

	SDL_Surface* surface{ NULL };
	surface = CreateSurfaceFromFile(rootPath + path);

	SDL_Texture* texture{ NULL };
	texture = CreateTextureFromSurface(surface);

	SDL_FreeSurface(surface);
	
	logger.Log(path);

	if (!texture)
	{
		logger.LogErrorSDL("Failed to load file \"" + path + "\"");
		return false;
	}
	sdlTexture = texture;
	return true;
}

SDL_Texture* Texture::GetSDLTexture()
{
	return sdlTexture;
}