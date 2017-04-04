#include "..\headers\Renderer.h"

Renderer::Renderer()
{
	InitSDL();
	InitSDLRenderer();
	dummyTexture.PassRenderer(rendererSDL);
}

Renderer::~Renderer()
{
	SDL_DestroyTexture(savedModifiedTexture);

	// destroys all textures
	SDL_DestroyRenderer(rendererSDL);
}

void Renderer::InitSDL()
{
	logger.Log("Initialising SDL...");
	SDL_Init(SDL_INIT_VIDEO);
	gameWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//SDL_SetWindowFullscreen(gameWindow, SDL_WINDOW_FULLSCREEN);
	if (!gameWindow)
		logger.LogErrorSDL("SDL window initialisation error." + (std::string)SDL_GetError());

	// linear texture filtering
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		logger.LogErrorSDL("Setting texture filtering to linear failed. " + (std::string)SDL_GetError());
}

void Renderer::InitSDLRenderer()
{
	rendererSDL = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!rendererSDL)
		logger.LogErrorSDL("SDL renderer initialisation error.");
	else
		SDL_SetRenderDrawColor(rendererSDL, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);
}

void Renderer::AddToQueue(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect)
{	

	SDL_Rect* finalSrcRect{ NULL };

	if (srcRect != NULL)
		finalSrcRect = srcRect;

	if (SDL_RenderCopy(rendererSDL, texture, finalSrcRect, dstRect) != 0)
		logger.LogErrorSDL("RenderCopy error.");

}

void Renderer::Clear()
{
	SDL_RenderClear(rendererSDL);
}

void Renderer::Render()
{
	SDL_RenderPresent(rendererSDL);
}