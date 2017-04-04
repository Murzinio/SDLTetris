#pragma once
#include "VisibleEntity.h"

class VisibleEntity;

class Board : 
	public VisibleEntity
{
private:
	SDL_Texture* texture = textures.GameBoard.GetSDLTexture();
	SDL_Rect dstRect{0, 0, SCREEN_WIDTH - SCREEN_WIDTH / 5, SCREEN_HEIGHT - SCREEN_HEIGHT / 10};

public:
	Board();
	~Board();

	void Draw();
};

